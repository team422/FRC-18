#pragma once

#include <WPILib.h>

class DriveStraightBeamBreak : public frc::Command {
public:
	DriveStraightBeamBreak(float speed, float timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	float speed;
};
