#pragma once

#include <WPILib.h>

class DriveStraight : public frc::Command {
public:
	DriveStraight(float inches, float speed, bool forward, float timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	int convertToTicks(float inches);
	int ticks;
	bool forward;
	float speed;
};
