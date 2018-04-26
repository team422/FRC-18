#pragma once

#include <WPILib.h>

class IntakeGrab : public frc::Command {
public:
	IntakeGrab();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
};

