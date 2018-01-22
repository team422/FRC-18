#pragma once

#include <WPILib.h>

class DriveStraight : public frc::Command {
public:
	DriveStraight(float inches);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	int convertToTicks(float inches);
	int ticks;
};
