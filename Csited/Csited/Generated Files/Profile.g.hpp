﻿

//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"
#include "Profile.xaml.h"




void ::Csited::Profile::InitializeComponent()
{
    if (_contentLoaded)
        return;

    _contentLoaded = true;

    // Call LoadComponent on ms-appx:///Profile.xaml
    ::Windows::UI::Xaml::Application::LoadComponent(this, ref new ::Windows::Foundation::Uri(L"ms-appx:///Profile.xaml"), ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);

    // Get the Image named 'displayImage'
    displayImage = safe_cast<::Windows::UI::Xaml::Controls::Image^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"displayImage"));
    // Get the TextBox named 'nameUser'
    nameUser = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"nameUser"));
    // Get the TextBox named 'fechaNacimiento'
    fechaNacimiento = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"fechaNacimiento"));
    // Get the TextBox named 'ciudad'
    ciudad = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"ciudad"));
    // Get the TextBox named 'email'
    email = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"email"));
    // Get the TextBox named 'fechaCompra'
    fechaCompra = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"fechaCompra"));
    // Get the StackPanel named 'tusProductos'
    tusProductos = safe_cast<::Windows::UI::Xaml::Controls::StackPanel^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"tusProductos"));
}

void ::Csited::Profile::Connect(int connectionId, Platform::Object^ target)
{
    switch (connectionId)
    {
    case 1:
        (safe_cast<::Windows::UI::Xaml::UIElement^>(target))->DoubleTapped +=
            ref new ::Windows::UI::Xaml::Input::DoubleTappedEventHandler(this, (void (::Csited::Profile::*)(Platform::Object^, Windows::UI::Xaml::Input::DoubleTappedRoutedEventArgs^))&Profile::GetPhotoDoubleTapped);
        break;
    }
    (void)connectionId; // Unused parameter
    (void)target; // Unused parameter
    _contentLoaded = true;
}
