//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"
#include "SampleConfiguration.h"
namespace App1{
	public enum class NotifyType
	{
		StatusMessage,
		ErrorMessage
	};
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
	private:
		void ScenarioControl_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);

		static MainPage^ Current;
		void NotifyUser(Platform::String^ strMessage, NotifyType type);
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;

	};
}
