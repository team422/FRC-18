#pragma once

#include <WPILib.h>

class LeftAutonomous: public frc::CommandGroup {
public:
	LeftAutonomous();
	void setShouldScore(std::string gameData, bool scale);
};
