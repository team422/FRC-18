#pragma once

#include <WPILib.h>
#include "Subsystems/Subsystems.hpp"
#include "Commands/Autonomous/LeftAutonomous.hpp"
#include "Commands/Autonomous/RightAutonomous.hpp"
#include "Commands/Autonomous/CenterAutonomous.hpp"

class Robot : public frc::IterativeRobot {
public:
	Robot() : leftAuto(), centerAuto(), rightAuto() {}
	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void printDataToSmartDashboard();
private:
	cs::UsbCamera camera;
	LeftAutonomous leftAuto;
	CenterAutonomous centerAuto;
	RightAutonomous rightAuto;
};
