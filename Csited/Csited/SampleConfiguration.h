//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

#pragma once

#include <collection.h>

namespace Csited
{
	public value struct Scenario
	{
		Platform::String^ Title;
		Platform::String^ ClassName;
		Platform::String^ _pathImage;
	};

	partial ref class MainPage
	{
	public:
		static property Platform::String^ FEATURE_NAME
		{
			Platform::String^ get()
			{
				return ref new Platform::String(L"ApplicationData");
			}
		}

		static property Platform::Array<Scenario>^ scenarios
		{
			Platform::Array<Scenario>^ get()
			{
				return scenariosInner;
			}
		}
	private:
		static Platform::Array<Scenario>^ scenariosInner;
	};


}