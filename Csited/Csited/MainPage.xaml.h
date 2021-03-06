﻿//
// MainPage.xaml.h
// Declaration of the MainPage class
//

#pragma once

#include "MainPage.g.h"
#include "Common\NavigationHelper.h"
#include "SampleConfiguration.h"
#include "Profile.xaml.h"

namespace Csited
{
	public enum class NotifyType
	{
		StatusMessage,
		ErrorMessage
	};
	/// <summary>
	/// A basic page that provides characteristics common to most applications.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class MainPage sealed
	{
	public:
		MainPage();

		/// <summary>
		/// This can be changed to a strongly typed view model.
		/// </summary>
		property Windows::Foundation::Collections::IObservableMap<Platform::String^, Platform::Object^>^ DefaultViewModel
		{
			Windows::Foundation::Collections::IObservableMap<Platform::String^, Platform::Object^>^  get();
		}

		/// <summary>
		/// NavigationHelper is used on each page to aid in navigation and 
		/// process lifetime management
		/// </summary>
		property Common::NavigationHelper^ NavigationHelper
		{
			Common::NavigationHelper^ get();
		}

	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
		virtual void OnNavigatedFrom(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	private:
		void LoadState(Platform::Object^ sender, Common::LoadStateEventArgs^ e);
		void SaveState(Platform::Object^ sender, Common::SaveStateEventArgs^ e);

		static Windows::UI::Xaml::DependencyProperty^ _defaultViewModelProperty;
		static Windows::UI::Xaml::DependencyProperty^ _navigationHelperProperty;

		//NUEVO
		void ScenarioControl_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);

		static MainPage^ Current;
		Profile^ Pro;
		void NotifyUser(Platform::String^ strMessage, NotifyType type);
		void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);

	};
}
