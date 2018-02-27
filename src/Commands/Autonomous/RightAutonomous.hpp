#pragma once

#include <WPILib.h>

class RightAutonomous: public frc::CommandGroup {
public:
	RightAutonomous();
	void setShouldScore(bool scale, bool shouldScore);
};
