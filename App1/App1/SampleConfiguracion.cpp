#include "pch.h"
#include "MainPage.xaml.h"
#include "SampleConfiguration.h"

using namespace Csited;

Platform::Array<Scenario>^ MainPage::scenariosInner = ref new Platform::Array<Scenario>
{
	// The format here is the following:
	//     { "Description for the sample", "Fully quaified name for the class that implements the scenario" }
	{ "Profile", "Csited.Profile" },
	

};