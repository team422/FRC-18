#pragma once

#include <WPILib.h>

class DriveStraight : public frc::Command {
public:
	DriveStraight(float inches, float speed, float timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	int convertToTicks(float inches);
	int ticks;
	float speed;
	float timeout;
};
