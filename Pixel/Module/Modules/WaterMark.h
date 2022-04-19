#pragma once
#include "Module.h"
class WaterMark : public IModule {
public:
	WaterMark();
	~WaterMark();

	bool tabgui = false;
	bool rainbow = true;
	bool textShadow = false;
	bool watermark = true;



	// Inherited via IModule
	virtual const char* getModuleName() override;
};
