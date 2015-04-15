//
// ItemsPage1.xaml.cpp
// Implementation of the Environment class
//

#include "pch.h"
#include "Environment.xaml.h"

using namespace Csited;

using namespace Platform;
using namespace Platform::Collections;
using namespace concurrency;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::ViewManagement;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Shapes;

// The Items Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234233

Environment::Environment()
{
	InitializeComponent();
	SetValue(_defaultViewModelProperty, ref new Map<String^,Object^>(std::less<String^>()));
	auto navigationHelper = ref new Common::NavigationHelper(this);
	SetValue(_navigationHelperProperty, navigationHelper);
	navigationHelper->LoadState += ref new Common::LoadStateEventHandler(this, &Environment::LoadState);
	auto entornos = ref new Vector < Entorno^ > ;
	entornos->Append(ref new Entorno(L"Antonio", L"Assets/Entorno-Casa-Cuadro-Azul.jpg"));
	entornos->Append(ref new Entorno(L"PEpe", L"Assets/csited.jpg"));
	entornos->Append(ref new Entorno(L"Juanito", L"Assets/csited.jpg"));

	itemGridView->ItemsSource = entornos;

	
}

DependencyProperty^ Environment::_defaultViewModelProperty =
	DependencyProperty::Register("DefaultViewModel",
		TypeName(IObservableMap<String^,Object^>::typeid), TypeName(Environment::typeid), nullptr);

/// <summary>
/// used as a trivial view model.
/// </summary>
IObservableMap<String^, Object^>^ Environment::DefaultViewModel::get()
{
	return safe_cast<IObservableMap<String^, Object^>^>(GetValue(_defaultViewModelProperty));
}

DependencyProperty^ Environment::_navigationHelperProperty =
	DependencyProperty::Register("NavigationHelper",
		TypeName(Common::NavigationHelper::typeid), TypeName(Environment::typeid), nullptr);

/// <summary>
/// Gets an implementation of <see cref="NavigationHelper"/> designed to be
/// used as a trivial view model.
/// </summary>
Common::NavigationHelper^ Environment::NavigationHelper::get()
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

void Environment::OnNavigatedTo(NavigationEventArgs^ e)
{
	NavigationHelper->OnNavigatedTo(e);
	auto text = ref new TextBox();
	text->Text = "Hola Buenos días";
	text->FontSize = 20;

	pizarra->Children->Append(text);
}

void Environment::OnNavigatedFrom(NavigationEventArgs^ e)
{
	NavigationHelper->OnNavigatedFrom(e);
}

#pragma endregion

/// <summary>
/// Populates the page with content passed during navigation.  Any saved state is also
/// provided when recreating a page from a prior session.
/// </summary>
/// <param name="navigationParameter">The parameter value passed to
/// <see cref="Frame::Navigate(Type, Object)"/> when this page was initially requested.
/// </param>
/// <param name="pageState">A map of state preserved by this page during an earlier
/// session.  This will be null the first time a page is visited.</param>
void Environment::LoadState(Platform::Object^ sender, Common::LoadStateEventArgs^ e)
{
	(void) sender;	// Unused parameter
	(void) e;	// Unused parameter

	// TODO: Set a bindable collection of items using DefaultViewModel->("Items", <value>)
}


void Csited::Environment::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Platform::Collections::Vector<String^>^ itemsList =
		ref new Platform::Collections::Vector<String^>();
	itemsList->Append("Item 1");
	itemsList->Append("Item 2");

	// Create a new grid view, add content, 
	// and add a SelectionChanged event handler.
	GridView^ gridView1 = ref new GridView();
	gridView1->ItemsSource = itemsList;
	gridView1->SelectionChanged +=
		ref new SelectionChangedEventHandler(this, &Environment::GridView_SelectionChanged);

	// Add the grid view to a parent container in the visual tree.
	auto text = ref new TextBox();
	text->Text = "Hola Buenos días";
	text->FontSize = 20;

	pizarra->Children->Append(text);

}


void Csited::Environment::GridView_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{

}
