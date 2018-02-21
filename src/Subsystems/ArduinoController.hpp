#pragma once

#include <WPILib.h>

class ArduinoController {
public:
	ArduinoController();
	void sendCommand(std::string analogReading, std::string primaryColor, std::string secondaryColor, std::string shoulderColor, std::string mode);
	void sendCommand(std::string command);
private:
	SerialPort port;
};

