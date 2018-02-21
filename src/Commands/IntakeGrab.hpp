#pragma once

#include <WPILib.h>

class IntakeGrab : public frc::Command {
public:
	IntakeGrab();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

