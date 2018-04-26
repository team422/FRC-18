#pragma once

#include <WPILib.h>

class DriveStraightBeamBreak : public frc::Command {
public:
	DriveStraightBeamBreak(double speed, double timeout);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
private:
	double speed;
};
