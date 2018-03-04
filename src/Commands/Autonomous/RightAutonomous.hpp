#pragma once

#include <WPILib.h>

class RightAutonomous: public frc::CommandGroup {
public:
	RightAutonomous();
	void setShouldScore(char side, bool scale);
};
