#pragma once

#include <WPILib.h>

class GuillotineKick: public frc::Command {
public:
	GuillotineKick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

