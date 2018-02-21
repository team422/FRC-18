#pragma once

#include <WPILib.h>

class LeftAutonomous: public frc::CommandGroup {
public:
	LeftAutonomous();
	void setShouldScore(bool scale, bool shouldScore);
};
