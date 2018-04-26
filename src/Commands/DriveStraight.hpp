#pragma once

#include <WPILib.h>

#include "../Util/Direction.hpp"

class DriveStraight : public frc::Command {
public:
	DriveStraight(double inches, double speed, Direction direction, double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	int convertToTicks(double inches);
	int ticks;
    Direction direction;
	double speed;
};
