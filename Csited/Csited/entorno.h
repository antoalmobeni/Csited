#pragma once
namespace Csited {
	[Windows::UI::Xaml::Data::BindableAttribute]
	public ref class Entorno sealed
	{
	public:
		Entorno(Platform::String^ _title, Platform::String^ _imagePatch){
			title = _title;
			imagePath = _imagePatch;
		}
		property Platform::String^ title;
		property Platform::String^ imagePath;

		
	};
}
