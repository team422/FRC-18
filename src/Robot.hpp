#pragma once

#include <WPILib.h>
#include "Subsystems/Subsystems.hpp"

#include "Commands/Autonomous/LeftAutonomous.hpp"
#include "Commands/Autonomous/RightAutonomous.hpp"
#include "Commands/Autonomous/CenterAutonomous.hpp"

class Robot : public frc::IterativeRobot {
public:
	Robot() : autonomous(nullptr) {}
	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
private:
	void printDataToSmartDashboard();
	void destroyAutonomous();
	cs::UsbCamera camera;
	CommandBatch *autonomous;
	bool isLast30Seconds = false;
	double currentGuillotinePosition = 0;
};
