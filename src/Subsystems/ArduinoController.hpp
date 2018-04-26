#pragma once

#include <WPILib.h>

class ArduinoController {
public:
	ArduinoController();
	void sendCommand(std::string command);
	static char getAllianceColorCode();
private:
	SerialPort port;
};

