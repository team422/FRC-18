#pragma once

#include <WPILib.h>

class GuillotineLower: public frc::Command {
public:
	GuillotineLower();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
};

