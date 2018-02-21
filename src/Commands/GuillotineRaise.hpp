#pragma once

#include <WPILib.h>

class GuillotineRaise: public frc::Command {
public:
	GuillotineRaise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

