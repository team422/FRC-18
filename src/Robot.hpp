#pragma once

#include <WPILib.h>
#include "Subsystems/Subsystems.hpp"
#include "Commands/DriveStraight.hpp"
#include "Commands/Turn.hpp"
#include "Commands/RightAutonomous.hpp"
#include "Commands/LeftAutonomous.hpp"

class Robot : public frc::IterativeRobot {

public:
	Robot() {}
	void RobotInit();
	void DisabledInit() {}
	void DisabledPeriodic() {}
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
private:
	RightAutonomous rightAuto;
	LeftAutonomous leftAuto;
};
