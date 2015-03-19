#include "pch.h"
#include "MainPage.xaml.h"
#include "SampleConfiguration.h"

using namespace App1;

Platform::Array<Scenario>^ MainPage::scenariosInner = ref new Platform::Array<Scenario>
{
	// The format here is the following:
	//     { "Description for the sample", "Fully quaified name for the class that implements the scenario" }
	{ "Files", "SDKSample.ApplicationDataSample.Files" },
	{ "Settings", "SDKSample.ApplicationDataSample.Settings" },
	{ "Setting Containers", "SDKSample.ApplicationDataSample.SettingContainer" },
	{ "Composite Settings", "SDKSample.ApplicationDataSample.CompositeSettings" },
	{ "DataChanged Event", "SDKSample.ApplicationDataSample.DataChangedEvent" },
	{ "Roaming: HighPriority", "SDKSample.ApplicationDataSample.HighPriority" },
	{ "ms-appdata:// Protocol", "SDKSample.ApplicationDataSample.Msappdata" },
	{ "Clear", "SDKSample.ApplicationDataSample.ClearScenario" },
	{ "SetVersion", "SDKSample.ApplicationDataSample.SetVersion" },
};