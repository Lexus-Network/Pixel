#pragma once
#include "Module.h"

class Spammer : public IModule {
private:
	int Odelay = 0;
	int delay = 2;
	int gamer = 0;

	bool custom = false;

	// Addon modes
	bool bypass = false;
	bool bypassv2 = false;
	bool hash = false;
	bool discord = false;
	//int Odelay = 0;
	///int delay = 2;
	int length = 8;

	std::string message = "Why lose when Pixel client is downloadable";
	std::string message2 = "This gaming chair is to pixel client op";
	std::string message3 = "You cant run from .tp";
	std::string message4 = "Popbob plays here, using pixel client";
	std::string playerName = "";

	std::string customMessage = "pixel client is cooler then u";
	std::string customMessage2 = "HELPP!!! I .ejected PIXEL CLIENT!1!!";
	std::string customMessagee3 = "IM PLAYING VANILLA RN~!~1";
	std::string customMessage4 = "I LOVE THIS XRAY BUT PIXEL CLIENT HAS .give???";
	// custom message 2,3 and 4 are here just incase anyone wants more :D

	SettingEnum spamMode;
	SettingEnum extensionMode;

public:
	Spammer();
	~Spammer();

	inline std::string& getCustomMessage() { return customMessage; };
	inline std::string& getCustomMessage2() { return customMessage; };
	inline std::string& getCustomMessage3() { return customMessage; };
	inline std::string& getCustomMessage4() { return customMessage; };
	inline int& getDelay() { return delay; };
	inline bool& getBypass() { return bypass; };

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
	virtual void onEnable();
};