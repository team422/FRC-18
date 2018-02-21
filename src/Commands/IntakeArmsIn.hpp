#pragma once

#include <WPILib.h>

class IntakeArmsIn: public frc::Command {
public:
	IntakeArmsIn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

