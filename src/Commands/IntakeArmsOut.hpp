#pragma once

#include <WPILib.h>

class IntakeArmsOut: public frc::Command {
public:
	IntakeArmsOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

