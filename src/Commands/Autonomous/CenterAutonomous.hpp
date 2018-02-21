#pragma once

#include <WPILib.h>

class CenterAutonomous: public frc::CommandGroup {
public:
	CenterAutonomous();
	void setSideToScore(char c, int side, bool score);
};

