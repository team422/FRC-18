#pragma once

#include <WPILib.h>
#include "Subsystems/Subsystems.hpp"

#include "Commands/Autonomous/LeftAutonomous.hpp"
#include "Commands/Autonomous/RightAutonomous.hpp"
#include "Commands/Autonomous/CenterAutonomous.hpp"
#include "Commands/Autonomous/PixyTest.hpp"

#include "Commands/DriveAndTargetCube.hpp"

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
	void setRobotLightMode();
	cs::UsbCamera camera;
	CommandBatch *autonomous;
	bool isLast30Seconds = false;
	double currentGuillotinePosition = 0;
	std::shared_ptr<NetworkTable> pixyTable;

};
