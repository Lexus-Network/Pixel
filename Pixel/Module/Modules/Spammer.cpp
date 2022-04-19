#include "Spammer.h"

#include "../../../Utils/Utils.h"
#include "../ModuleManager.h"

Spammer::Spammer() : IModule(0x0, Category::MISC, "Spams a message in a specified delay") {
	registerIntSetting("delay", &this->delay, this->delay, 0, 10);

	registerEnumSetting("Text Modes", &spamMode, 0);
	spamMode = SettingEnum(this)
				   .addEntry(EnumEntry("Default", 0))
				   .addEntry(EnumEntry("Gloat", 1))
				   .addEntry(EnumEntry("Excuse", 2))
				   .addEntry(EnumEntry("Honour", 3))
				   .addEntry(EnumEntry("Lunes", 4))
				   .addEntry(EnumEntry("Symbol", 5));

	registerEnumSetting("Extensions", &extensionMode, 0);
	extensionMode = SettingEnum(this)
						.addEntry(EnumEntry("None", 0))
						.addEntry(EnumEntry("Normal", 1))
						.addEntry(EnumEntry("Discord", 2))
						.addEntry(EnumEntry("Bypass", 3))
						.addEntry(EnumEntry("Bypass+", 4));

	registerBoolSetting("Custom Message", &custom, custom);
}

Spammer::~Spammer() {
}

const char* Spammer::getModuleName() {
	return ("Spammer");
}

void Spammer::onTick(C_GameMode* gm) {
	switch (spamMode.selected) {
	case 0:
		message = "You are hiding because of Pixel Client!!>??!";
		message2 = "HE CRIED FROM PIZXEL CLIXZENT";
		message3 = "Why run when pixel client has .tp and .coords!!!/!??/";
		message4 = "CURB STOMPIN KIDS WIT PIXEL CLIENT!1!!!";
		break;

	case 1:
		message = "WOW! NICE CONFIG";
		message2 = "Need diamonds? .give diamond 64!";
		message3 = "Dont use the .cbe command";
		message4 = "Bro got cpvped by Pixel Bot";
		break;

	case 2:
		message = "Dont ban me, im testing!!!";
		message2 = "SHIT CONFIG";
		message3 = "WHY DONT U DOWNLOAD PIXEL CLIENT RN!";
		message4 = "Use pixel client default config instead!";
		break;

	case 3:
		message = "STFU BITCH";
		message2 = "GET SHIT ON ESJGSGN";
		message3 = "I WORSHIP PIXEL";
		message4 = "POP BOB USES PIXEL";
		break;

	case 4:
		if (g_Data.isInGame()) {
			playerName = g_Data.getLocalPlayer()->getNameTag()->getText();
		}

		message = "Hi my name is " + playerName + " and i like men";
		message2 = "Did you know that " + playerName + " has a better config?";
		message3 = "If your not " + playerName + " your not gaming";
		message4 = "Bro be like " + playerName + " hes using pixel client";
		break;

	case 5:
		message = "";
		message2 = "";
		message3 = "";
		message4 = "";
		break;
	}

	switch (extensionMode.selected) {
	case 0:
		bypass = false;
		hash = false;
		discord = false;
		break;

	case 1:
		bypass = false;
		hash = true;
		discord = false;
		break;

	case 2:
		bypass = false;
		hash = false;
		discord = true;
		break;

	case 3:
		bypass = true;
		hash = false;
		discord = false;
		break;

	case 4:
		bypassv2 = true;
		bypass = false;
		hash = false;
		discord = false;
		break;
	}

	if (!custom) {
		Odelay++;
		if (gamer == 0) {
			if (Odelay > delay * 20) {
				C_TextPacket textPacket;
				textPacket.message.setText(bypass ? (message + " | " + Utils::randomString(8)) : bypassv2 ? (Utils::randomString(8) + " | " + message)
																							 : hash       ? (message + " curb stompinm")
																							 : discord    ? (message + " | discord.gg/pixelclient")
																										  : message);
				textPacket.sourceName.setText(g_Data.getLocalPlayer()->getNameTag()->getText());
				textPacket.xboxUserId = std::to_string(g_Data.getLocalPlayer()->getUserId());
				g_Data.getClientInstance()->loopbackPacketSender->sendToServer(&textPacket);
				Odelay = 0;
				gamer = 1;
			}
		}
		if (gamer == 1) {
			if (Odelay > delay * 20) {
				C_TextPacket textPacket;
				textPacket.message.setText(bypass ? (message2 + " | " + Utils::randomString(8)) : bypassv2 ? (Utils::randomString(8) + " | " + message2)
																							  : hash       ? (message2 + " BLAH CURP")
																							  : discord    ? (message2 + " | discord.gg/pixelclient")
																										   : message2);
				textPacket.sourceName.setText(g_Data.getLocalPlayer()->getNameTag()->getText());
				textPacket.xboxUserId = std::to_string(g_Data.getLocalPlayer()->getUserId());
				g_Data.getClientInstance()->loopbackPacketSender->sendToServer(&textPacket);
				Odelay = 0;
				gamer = 2;
			}
		}
		if (gamer == 2) {
			if (Odelay > delay * 20) {
				C_TextPacket textPacket;
				textPacket.message.setText(bypass ? (message3 + " | " + Utils::randomString(8)) : bypassv2 ? (Utils::randomString(8) + " | " + message3)
																							  : hash       ? (message3 + " COPIN")
																							  : discord    ? (message3 + " | discord.gg/pixelclient")
																										   : message3);
				textPacket.sourceName.setText(g_Data.getLocalPlayer()->getNameTag()->getText());
				textPacket.xboxUserId = std::to_string(g_Data.getLocalPlayer()->getUserId());
				g_Data.getClientInstance()->loopbackPacketSender->sendToServer(&textPacket);
				Odelay = 0;
				gamer = 3;
			}
		}
		if (gamer == 3) {
			if (Odelay > delay * 20) {
				C_TextPacket textPacket;
				textPacket.message.setText(bypass ? (message4 + " | " + Utils::randomString(8)) : bypassv2 ? (Utils::randomString(8) + " | " + message4)
																							  : hash       ? (message4 + " wait this is bypasin!")
																							  : discord    ? (message4 + " | discord.gg/pixelclient")
																										   : message4);
				textPacket.sourceName.setText(g_Data.getLocalPlayer()->getNameTag()->getText());
				textPacket.xboxUserId = std::to_string(g_Data.getLocalPlayer()->getUserId());
				g_Data.getClientInstance()->loopbackPacketSender->sendToServer(&textPacket);
				Odelay = 0;
				gamer = 0;
			}
		}
	} else {
		Odelay++;
		if (Odelay > delay * 20) {
			C_TextPacket textPacket;
			textPacket.message.setText(bypass ? (customMessage + " | " + Utils::randomString(8)) : bypassv2 ? (Utils::randomString(8) + " | " + customMessage)
																							   : hash       ? (customMessage + " sit down kid")
																							   : discord    ? (customMessage + " | discord.gg/pixelclient")
																											: customMessage);
			textPacket.sourceName.setText(g_Data.getLocalPlayer()->getNameTag()->getText());
			textPacket.xboxUserId = std::to_string(g_Data.getLocalPlayer()->getUserId());
			g_Data.getClientInstance()->loopbackPacketSender->sendToServer(&textPacket);
			Odelay = 0;
		}
	}
}

void Spammer::onEnable() {
	gamer = 0;
}