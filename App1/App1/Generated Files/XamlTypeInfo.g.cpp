﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "pch.h"
#include "XamlTypeInfo.g.h"

#include "App.xaml.h"
#include "MainPage.xaml.h"
#include "Profile.xaml.h"

#include "App.g.hpp"
#include "MainPage.g.hpp"
#include "Profile.g.hpp"

::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::OtherProviders::get()
{
    if(_otherProviders == nullptr)
    {
        _otherProviders = ref new ::Platform::Collections::Vector<::Windows::UI::Xaml::Markup::IXamlMetadataProvider^>();
    }
    return _otherProviders;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForName(::Platform::String^ typeName)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(typeName);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CheckOtherMetadataProvidersForType(::Windows::UI::Xaml::Interop::TypeName t)
{
    ::Windows::UI::Xaml::Markup::IXamlType^ foundXamlType = nullptr;
    for (unsigned int i = 0; i < OtherProviders->Size; i++)
    {
        auto xamlType = OtherProviders->GetAt(i)->GetXamlType(t);
        if(xamlType != nullptr)
        {
            if(xamlType->IsConstructible)    // not Constructible means it might be a Return Type Stub
            {
                return xamlType;
            }
            foundXamlType = xamlType;
        }
    }
    return foundXamlType;
}

::Windows::UI::Xaml::Markup::IXamlType^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlType(::Platform::String^ typeName)
{
    if (typeName == L"Windows.UI.Xaml.Controls.Page")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"Windows.UI.Xaml.Controls.UserControl")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"Object")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"String")
    {
        return ref new XamlSystemBaseType(typeName);
    }

    if (typeName == L"App1.MainPage")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::App1::MainPage(); 
            };
        userType->SetIsLocalType();
        return userType;
    }

    if (typeName == L"App1.Profile")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Windows.UI.Xaml.Controls.Page"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->Activator =
            []() -> Platform::Object^ 
            {
                return ref new ::App1::Profile(); 
            };
        userType->AddMemberName(L"NavigationHelper");
        userType->AddMemberName(L"DefaultViewModel");
        userType->SetIsLocalType();
        return userType;
    }

    if (typeName == L"App1.Common.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->AddMemberName(L"GoForwardCommand");
        userType->AddMemberName(L"GoBackCommand");
        userType->SetIsBindable();
        userType->SetIsLocalType();
        return userType;
    }

    if (typeName == L"Windows.Foundation.Collections.IObservableMap`2<String, Object>")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, nullptr);
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Metadata;
        userType->DictionaryAdd =
            [](Object^ instance, Object^ key, Object^ item) -> void
            {
                auto collection = (Windows::Foundation::Collections::IObservableMap<::Platform::String^, ::Platform::Object^>^)instance;
                auto newKey = (Platform::String^)key;
                auto newItem = (Platform::Object^)item;
                collection->Insert(newKey, newItem);
            };
        userType->SetIsReturnTypeStub();
        return userType;
    }

    if (typeName == L"App1.Common.RelayCommand")
    {
        ::XamlTypeInfo::InfoProvider::XamlUserType^ userType = ref new ::XamlTypeInfo::InfoProvider::XamlUserType(this, typeName, GetXamlTypeByName(L"Object"));
        userType->KindOfType = ::Windows::UI::Xaml::Interop::TypeKind::Custom;
        userType->SetIsReturnTypeStub();
        userType->SetIsLocalType();
        return userType;
    }

    return nullptr;
}

::Windows::UI::Xaml::Markup::IXamlMember^ ::XamlTypeInfo::InfoProvider::XamlTypeInfoProvider::CreateXamlMember(::Platform::String^ longMemberName)
{
    if (longMemberName == L"App1.Profile.NavigationHelper")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"NavigationHelper", L"App1.Common.NavigationHelper");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Profile^)instance;
                return that->NavigationHelper;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Profile.DefaultViewModel")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"DefaultViewModel", L"Windows.Foundation.Collections.IObservableMap`2<String, Object>");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Profile^)instance;
                return that->DefaultViewModel;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Common.NavigationHelper.GoForwardCommand")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"GoForwardCommand", L"App1.Common.RelayCommand");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Common::NavigationHelper^)instance;
                return that->GoForwardCommand;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    if (longMemberName == L"App1.Common.NavigationHelper.GoBackCommand")
    {
        ::XamlTypeInfo::InfoProvider::XamlMember^ xamlMember = ref new ::XamlTypeInfo::InfoProvider::XamlMember(this, L"GoBackCommand", L"App1.Common.RelayCommand");
        xamlMember->Getter =
            [](Object^ instance) -> Object^
            {
                auto that = (::App1::Common::NavigationHelper^)instance;
                return that->GoBackCommand;
            };

        xamlMember->SetIsReadOnly();
        return xamlMember;
    }

    return nullptr;
}
