#pragma once

#include <WPILib.h>

class IntakeArmsStop: public frc::Command {
public:
	IntakeArmsStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

