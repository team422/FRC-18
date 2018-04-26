#include "ArduinoController.hpp"

#include "../RobotMap.h"

/**
 * Represents a communication channel with the Arduino Controller
 *
 * Data can be sent using the sendCommand() method to be received by the Arduino
 */
ArduinoController::ArduinoController() : port(9600, SerialPort::Port::kUSB1) {

}

/**
 * Sends the given command to the Arduino
 * @param command The command string to be sent
 */
void ArduinoController::sendCommand(std::string command) {
#ifdef COMP_BOT
	port.Write("!" + command);
#endif
}

char ArduinoController::getAllianceColorCode() {
	if (DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed) {
		return '3';
	} else {
		return '2';
	}
}

