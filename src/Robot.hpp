#pragma once

#include <WPILib.h>
#include "Subsystems/Subsystems.hpp"

class Robot : public frc::IterativeRobot {

public:
	Robot() {}
	virtual ~Robot() {}
	void RobotInit() {}
	void DisabledInit() {}
	void DisabledPeriodic() {}
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
};
