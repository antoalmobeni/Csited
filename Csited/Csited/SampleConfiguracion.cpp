#include "pch.h"
#include "MainPage.xaml.h"
#include "SampleConfiguration.h"

using namespace Csited;

Platform::Array<Scenario>^ MainPage::scenariosInner = ref new Platform::Array<Scenario>
{
	// The format here is the following:
	//     { "Description for the sample", "Fully quaified name for the class that implements the scenario" }
	{ "Perfil", "Csited.Profile", "ms-appx:///Assets/perfil.png" },
	{ "Sincronización", "Csited.Sync","ms-appx:///Assets/Sincronizacion.png" },
	{ "Entornos", "Csited.Environment", "ms-appx:///Assets/Entornos.png" }
	

};