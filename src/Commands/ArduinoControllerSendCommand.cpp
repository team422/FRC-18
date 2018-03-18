#include "ArduinoControllerSendCommand.hpp"
#include "../Subsystems/Subsystems.hpp"

ArduinoControllerSendCommand::ArduinoControllerSendCommand() {

}

void ArduinoControllerSendCommand::Initialize() {
	if (DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed) {
		Subsystems::arduino.sendCommand("0005356");
	} else {
		Subsystems::arduino.sendCommand("0005256");
	}
}

bool ArduinoControllerSendCommand::IsFinished() {
	return true;
}

