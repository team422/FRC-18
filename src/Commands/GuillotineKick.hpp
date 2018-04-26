#pragma once

#include <WPILib.h>

class GuillotineKick : public frc::Command {
public:
	GuillotineKick();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
};

