﻿//
// Profile.xaml.cpp
// Implementation of the Profile class
//

#include "pch.h"
#include "Profile.xaml.h"

using namespace App1;

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

//Added
using namespace concurrency;

// The Basic Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234237

Profile::Profile()
{
	InitializeComponent();
	SetValue(_defaultViewModelProperty, ref new Map<String^,Object^>(std::less<String^>()));
	auto navigationHelper = ref new Common::NavigationHelper(this);
	SetValue(_navigationHelperProperty, navigationHelper);
	navigationHelper->LoadState += ref new Common::LoadStateEventHandler(this, &Profile::LoadState);
	navigationHelper->SaveState += ref new Common::SaveStateEventHandler(this, &Profile::SaveState);
}

DependencyProperty^ Profile::_defaultViewModelProperty =
	DependencyProperty::Register("DefaultViewModel",
		TypeName(IObservableMap<String^,Object^>::typeid), TypeName(Profile::typeid), nullptr);

/// <summary>
/// used as a trivial view model.
/// </summary>
IObservableMap<String^, Object^>^ Profile::DefaultViewModel::get()
{
	return safe_cast<IObservableMap<String^, Object^>^>(GetValue(_defaultViewModelProperty));
}

DependencyProperty^ Profile::_navigationHelperProperty =
	DependencyProperty::Register("NavigationHelper",
		TypeName(Common::NavigationHelper::typeid), TypeName(Profile::typeid), nullptr);

/// <summary>
/// Gets an implementation of <see cref="NavigationHelper"/> designed to be
/// used as a trivial view model.
/// </summary>
Common::NavigationHelper^ Profile::NavigationHelper::get()
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

void Profile::OnNavigatedTo(NavigationEventArgs^ e)
{
	NavigationHelper->OnNavigatedTo(e);
}

void Profile::OnNavigatedFrom(NavigationEventArgs^ e)
{
	NavigationHelper->OnNavigatedFrom(e);
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
void Profile::LoadState(Object^ sender, Common::LoadStateEventArgs^ e)
{
	(void) sender;	// Unused parameter
	(void) e;	// Unused parameter

	if (e->PageState != nullptr && e->PageState->HasKey("mruToken"))
	{
		Object^ value = e->PageState->Lookup("mruToken");
		if (value != nullptr)
		{
			mruToken = value->ToString();

			// Open the file via the token that you stored when adding this file into the MRU list::
			create_task(Windows::Storage::AccessCache::StorageApplicationPermissions::MostRecentlyUsedList->GetFileAsync(mruToken))
				.then([this](Windows::Storage::StorageFile^ file)
			{
				if (file != nullptr)
				{
					// Open a stream for the selected file->
					//  Windows.Storage->Streams.IRandomAccessStream fileStream =
					create_task(file->OpenAsync(Windows::Storage::FileAccessMode::Read))
						.then([this, file](Windows::Storage::Streams::IRandomAccessStream^ fileStream)
					{
						// Set the image source to a bitmap.
						auto bitmapImage =
							ref new Windows::UI::Xaml::Media::Imaging::BitmapImage();

						bitmapImage->SetSource(fileStream);
						displayImage->ImageSource = bitmapImage;

						// Set the data context for the page
						this->DataContext = file;
					});
				}
			});
		}
	}


}

/// <summary>
/// Preserves state associated with this page in case the application is suspended or the
/// page is discarded from the navigation cache.  Values must conform to the serialization
/// requirements of <see cref="SuspensionManager::SessionState"/>.
/// </summary>
/// <param name="sender">The source of the event; typically <see cref="NavigationHelper"/></param>
/// <param name="e">Event data that provides an empty dictionary to be populated with
/// serializable state.</param>
void Profile::SaveState(Object^ sender, Common::SaveStateEventArgs^ e){
	(void) sender;	// Unused parameter
	(void) e; // Unused parameter

	//Comprueba si existe el toke y, si es así, lo guarda en el diccionario PageState
	if (mruToken != nullptr && !mruToken->IsEmpty())
	{
		e->PageState->Insert("mruToken", mruToken);
	}

}


void App1::Profile::ImageBrush_ImageOpened(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void App1::Profile::Ellipse_DoubleTapped(Platform::Object^ sender, Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs^ e)
{
	auto openPicker = ref new Windows::Storage::Pickers::FileOpenPicker();
	openPicker->SuggestedStartLocation = Windows::Storage::Pickers::PickerLocationId::PicturesLibrary;
	openPicker->ViewMode = Windows::Storage::Pickers::PickerViewMode::Thumbnail;

	// Filter to include a sample subset of file types.
	openPicker->FileTypeFilter->Clear();
	openPicker->FileTypeFilter->Append(".bmp");
	openPicker->FileTypeFilter->Append(".png");
	openPicker->FileTypeFilter->Append(".jpeg");
	openPicker->FileTypeFilter->Append(".jpg");

	// All this work will be done asynchronously on a background thread:
	// Open the file picker.
	create_task(openPicker->PickSingleFileAsync()).then(
		[this](Windows::Storage::StorageFile^ file)
	{
		// file is null if user cancels the file picker.
		if (file != nullptr)
		{
			// Open a stream for the selected file.
			create_task([file]()
			{
				return file->OpenAsync(Windows::Storage::FileAccessMode::Read);
			}).then([this, file](Windows::Storage::Streams::IRandomAccessStream^ fileStream)
			{
				// Set the image source to the selected bitmap.
				Windows::UI::Xaml::Media::Imaging::BitmapImage^ bitmapImage =
					ref new Windows::UI::Xaml::Media::Imaging::BitmapImage();

				bitmapImage->SetSource(fileStream);
				displayImage->ImageSource = bitmapImage;
				this->DataContext = file;
			}).then([this, file]()
			{
				// Add picked file to MostRecentlyUsedList.
				mruToken = Windows::Storage::AccessCache::StorageApplicationPermissions::MostRecentlyUsedList->Add(file);
			});
		}
	});

}
