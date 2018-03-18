#pragma once

#include <WPILib.h>

class ArduinoControllerSendCommand : public frc::Command {
public:
	ArduinoControllerSendCommand();
	void Initialize() override;
	void Execute() override {}
	bool IsFinished() override;
	void Interrupted() override {}
	void End() override {}
};

