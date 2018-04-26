#pragma once

#include <WPILib.h>

class GuillotineRaise : public frc::Command {
public:
	GuillotineRaise();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
};

