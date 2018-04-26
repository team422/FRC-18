#pragma once

#include <WPILib.h>

class GuillotineLower: public frc::Command {
public:
	GuillotineLower();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
};

