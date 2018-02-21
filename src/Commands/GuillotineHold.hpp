#pragma once

#include <WPILib.h>

class GuillotineHold: public frc::Command {
public:
	GuillotineHold();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

