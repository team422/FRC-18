#pragma once

#include <WPILib.h>

class IntakeRelease: public frc::Command {
public:
	IntakeRelease();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

