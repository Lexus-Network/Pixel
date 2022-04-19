#include "WaterMark.h"

WaterMark::WaterMark() : IModule(0x0, Category::GUI, "Displays client watermark") {
	registerBoolSetting("TabGui", &tabgui, tabgui);
	registerBoolSetting("Watermark", &watermark, watermark);
	registerBoolSetting("TextShadow", &textShadow, textShadow);
	registerBoolSetting("Rainbow", &rainbow, rainbow);
	//registerFloatSetting("Scale", &scale, scale, 0.5f, 1.5f);
}

WaterMark::~WaterMark() {
}

const char* WaterMark::getModuleName() {
	return ("GUI");
}
