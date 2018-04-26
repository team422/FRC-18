#pragma once

#include <WPILib.h>

class IntakeRelease : public frc::Command {
public:
	IntakeRelease();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
};

