#pragma once

#include <WPILib.h>

class GuillotineHold : public frc::Command {
public:
	GuillotineHold();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
};

