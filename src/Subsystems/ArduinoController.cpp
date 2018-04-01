#include "ArduinoController.hpp"

#include "../RobotMap.h"

ArduinoController::ArduinoController() : port(9600, SerialPort::Port::kUSB1) {

}

void ArduinoController::sendCommand(std::string analogReading, std::string primaryColor, std::string secondaryColor, std::string shoulderColor, std::string mode) {
	std::string command = primaryColor;
	command += secondaryColor;
	command += shoulderColor;
	command += mode;
	sendCommand(command);
}

void ArduinoController::sendCommand(std::string command) {
#ifdef COMP_BOT
	port.Write("!" + command);
#endif
}

