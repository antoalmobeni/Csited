// MainPage.xaml.cpp
// Implementation of the MainPage class
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "Profile.xaml.h"
using namespace Csited;
using namespace Csited::Common;

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Basic Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234237
MainPage^ MainPage::Current = nullptr;

MainPage::MainPage()
{
	InitializeComponent();
	SetValue(_defaultViewModelProperty, ref new Map<String^,Object^>(std::less<String^>()));
	auto navigationHelper = ref new Common::NavigationHelper(this);
	SetValue(_navigationHelperProperty, navigationHelper);
	navigationHelper->LoadState += ref new Common::LoadStateEventHandler(this, &MainPage::LoadState);
	navigationHelper->SaveState += ref new Common::SaveStateEventHandler(this, &MainPage::SaveState);

	// This is a static public property that allows downstream pages to get a handle to the MainPage instance
	// in order to call methods that are in this class.
	MainPage::Current = this;

}

DependencyProperty^ MainPage::_defaultViewModelProperty =
	DependencyProperty::Register("DefaultViewModel",
		TypeName(IObservableMap<String^,Object^>::typeid), TypeName(MainPage::typeid), nullptr);

/// <summary>
/// used as a trivial view model.
/// </summary>
IObservableMap<String^, Object^>^ MainPage::DefaultViewModel::get()
{
	return safe_cast<IObservableMap<String^, Object^>^>(GetValue(_defaultViewModelProperty));
}

DependencyProperty^ MainPage::_navigationHelperProperty =
	DependencyProperty::Register("NavigationHelper",
		TypeName(Common::NavigationHelper::typeid), TypeName(MainPage::typeid), nullptr);

/// <summary>
/// Gets an implementation of <see cref="NavigationHelper"/> designed to be
/// used as a trivial view model.
/// </summary>
Common::NavigationHelper^ MainPage::NavigationHelper::get()
{
	return safe_cast<Common::NavigationHelper^>(GetValue(_navigationHelperProperty));
}

#pragma region Navigation support

/// The methods provided in this section are simply used to allow
/// NavigationHelper to respond to the page's navigation methods.
/// 
/// Page specific logic should be placed in event handlers for the  
/// <see cref="NavigationHelper::LoadState"/>
/// and <see cref="NavigationHelper::SaveState"/>.
/// The navigation parameter is available in the LoadState method 
/// in addition to page state preserved during an earlier session.

void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	NavigationHelper->OnNavigatedTo(e);
	// Populate the ListBox with the scenarios as defined in SampleConfiguration.cpp.
	auto itemCollection = ref new Platform::Collections::Vector<Object^>();
	int i = 1;
	for each(Scenario s in MainPage::Current->scenarios)
	{
		// Create a textBlock to hold the content and apply the ListItemTextStyle from Styles.xaml
		TextBlock^ textBlock = ref new TextBlock();
		Button^ button = ref new Button();
		ListBoxItem^ item = ref new ListBoxItem();
		auto style = App::Current->Resources->Lookup("ListItemTextStyle");
		auto style2 = App::Current->Resources->Lookup("ListItemButtonStyle");
		

		textBlock->Text = s.Title;
		textBlock->Style = safe_cast<Windows::UI::Xaml::Style ^>(style);
		
		button->Content = (i++).ToString() + ") " + s.Title;
		button->Style = safe_cast<Windows::UI::Xaml::Style ^>(style2);
		


		item->Name = s.ClassName;
		item->Content = textBlock;
		itemCollection->Append(item);
	}

	// Set the newly created itemCollection as the ListBox ItemSource.
	ScenarioControl->ItemsSource = itemCollection;

	// Set selected scenario to the first scenario (0) or if we resumed from a PLM termination set it to
	// the previously selected scenario.
	int startingScenarioIndex = 0;

	if (SuspensionManager::SessionState()->HasKey("SelectedScenarioIndex"))
	{
		startingScenarioIndex = safe_cast<int>(SuspensionManager::SessionState()->Lookup("SelectedScenarioIndex"));
	}

	ScenarioControl->SelectedIndex = startingScenarioIndex;
	ScenarioControl->ScrollIntoView(ScenarioControl->SelectedItem);

	
	
}
void MainPage::ScenarioControl_SelectionChanged(Object^ sender, SelectionChangedEventArgs^ e)
{
	ListBox^ scenarioListBox = safe_cast<ListBox^>(sender); //as ListBox;
	ListBoxItem^ item = dynamic_cast<ListBoxItem^>(scenarioListBox->SelectedItem);

	if (item != nullptr)
	{
		// Clear the status block when changing scenarios
		NotifyUser("", NotifyType::StatusMessage);

		// Store the selected scenario in SuspensionManager
		SuspensionManager::SessionState()->Insert("SelectedScenarioIndex", scenarioListBox->SelectedIndex);

		// Navigate to the selected scenario.
		TypeName scenarioType = { item->Name, TypeKind::Custom };
		ScenarioFrame->Navigate(scenarioType, this);
	}
}
void MainPage::NotifyUser(String^ strMessage, NotifyType type)
{
	//switch (type)
	//{
	//case NotifyType::StatusMessage:
	//	StatusBorder->Background = ref new SolidColorBrush(Windows::UI::Colors::Green);
	//	break;
	//case NotifyType::ErrorMessage:
	//	StatusBorder->Background = ref new SolidColorBrush(Windows::UI::Colors::Red);
	//	break;
	//default:
	//	break;
	//}
	//StatusBlock->Text = strMessage;

	//// Collapse the StatusBlock if it has no text to conserve real estate.
	//if (StatusBlock->Text != "")
	//{
	//	StatusBorder->Visibility = Windows::UI::Xaml::Visibility::Visible;
	//}
	//else
	//{
	//	StatusBorder->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	//}
}

void MainPage::OnNavigatedFrom(NavigationEventArgs^ e)
{
	// Populate the ListBox with the scenarios as defined in SampleConfiguration.cpp.
	/*auto itemCollection = ref new Platform::Collections::Vector<Object^>();
	int i = 1;
	for each(Scenario s in MainPage::Current->scenarios)
	{
		s.OnNavigatedTo
	}*/
	
}
#pragma endregion

/// <summary>
/// Populates the page with content passed during navigation. Any saved state is also
/// provided when recreating a page from a prior session.
/// </summary>
/// <param name="sender">
/// The source of the event; typically <see cref="NavigationHelper"/>
/// </param>
/// <param name="e">Event data that provides both the navigation parameter passed to
/// <see cref="Frame.Navigate(Type, Object)"/> when this page was initially requested and
/// a dictionary of state preserved by this page during an earlier
/// session. The state will be null the first time a page is visited.</param>
void MainPage::LoadState(Object^ sender, Common::LoadStateEventArgs^ e)
{
	(void) sender;	// Unused parameter
	(void) e;	// Unused parameter
}

/// <summary>
/// Preserves state associated with this page in case the application is suspended or the
/// page is discarded from the navigation cache.  Values must conform to the serialization
/// requirements of <see cref="SuspensionManager::SessionState"/>.
/// </summary>
/// <param name="sender">The source of the event; typically <see cref="NavigationHelper"/></param>
/// <param name="e">Event data that provides an empty dictionary to be populated with
/// serializable state.</param>
void MainPage::SaveState(Object^ sender, Common::SaveStateEventArgs^ e){
	(void) sender;	// Unused parameter
	(void) e; // Unused parameter
}
