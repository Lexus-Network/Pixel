#include "FontChanger.h"
FontChanger::FontChanger() : IModule(0, Category::GUI, "Font Changer") {
	registerEnumSetting("Fonts", &Fonts, 0);
	Fonts = SettingEnum(this)
				.addEntry(EnumEntry("Normal", 0))
				.addEntry(EnumEntry("Old", 1));
}
FontChanger::~FontChanger() {
}
const char* FontChanger::getModuleName() {
	return ("Fonts");
}
