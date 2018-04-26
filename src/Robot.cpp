#include "Robot.hpp"
#include "Commands/IntakeBox.hpp"
#include "Commands/IntakeGrab.hpp"
#include "Commands/IntakeRelease.hpp"
#include "Commands/GuillotineHold.hpp"
#include "Commands/GuillotineKick.hpp"
#include "UserInterface/UI.hpp"
#include <cmath>
#include <networktables/NetworkTableInstance.h>

void Robot::RobotInit() {
	Subsystems::compressor.Start();
	UserInterface::userInterface.controller.A.WhenPressed(new IntakeGrab());
	UserInterface::userInterface.controller.B.WhenPressed(new IntakeRelease());
	UserInterface::userInterface.controller.LB.WhenPressed(new GuillotineHold());
	UserInterface::userInterface.controller.RB.WhenPressed(new GuillotineKick());
	UserInterface::userInterface.controller.START.WhenPressed(new IntakeBox());
	camera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	pixyTable = nt::NetworkTableInstance::GetDefault().GetTable("pixy");
	Subsystems::arduino.sendCommand("0001111");
	Subsystems::guillotine.zeroLiftPosition();
	currentGuillotinePosition = floor((double) ((double) Subsystems::guillotine.getLiftPosition()) / 20.0d);
	isLast30Seconds = false;
}

void Robot::DisabledInit() {
	Subsystems::arduino.sendCommand("0001111");
	destroyAutonomous();
	pixyTable->PutString("target_type", "area");
}

void Robot::DisabledPeriodic() {
	printDataToSmartDashboard();
}

void Robot::AutonomousInit() {
	Subsystems::arduino.sendCommand("0005551");
	std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if (UserInterface::userInterface.launchpad.getMultiSwitchLeft()) {
		pixyTable->PutString("target_type", "right");
		autonomous = new LeftAutonomous(gameData, UserInterface::userInterface.launchpad.getSwitch1());
	} else if (UserInterface::userInterface.launchpad.getMultiSwitchInactive()) {
		pixyTable->PutString("target_type", "area");
		autonomous = new CenterAutonomous(gameData[0]);
	} else if (UserInterface::userInterface.launchpad.getMultiSwitchRight()) {
		pixyTable->PutString("target_type", "left");
		autonomous = new RightAutonomous(gameData, UserInterface::userInterface.launchpad.getSwitch1());
	}
	autonomous->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	printDataToSmartDashboard();
}

void Robot::TeleopInit() {
	if (DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed) {
		Subsystems::arduino.sendCommand("0003331");
	} else {
		Subsystems::arduino.sendCommand("0002221");
	}
	destroyAutonomous();
	pixyTable->PutString("target_type", "left");
}

void Robot::TeleopPeriodic() {
	Subsystems::guillotine.setLiftSpeed(0.0f);
	if (UserInterface::userInterface.controller.getPOVAngle() == 270) {
		Subsystems::intake.release();
		if (Subsystems::guillotine.getLiftPosition() < 756) {
			Subsystems::guillotine.setLiftSpeed(1.0f);
		} else {
			Subsystems::guillotine.setLiftSpeed(0.25f);
		}
	} else if (UserInterface::userInterface.controller.getPOVAngle() == 0) {
		Subsystems::intake.release();
		if (Subsystems::guillotine.getLiftPosition() < 1500) {
			Subsystems::guillotine.setLiftSpeed(1.0f);
		} else {
			Subsystems::guillotine.setLiftSpeed(0.25f);
		}
	} else if (UserInterface::userInterface.controller.getPOVAngle() == 90) {
		Subsystems::intake.release();
		if (Subsystems::guillotine.getLiftPosition() < 1800) {
			Subsystems::guillotine.setLiftSpeed(1.0f);
		} else {
			Subsystems::guillotine.setLiftSpeed(0.25f);
		}
	} else if (UserInterface::userInterface.controller.getPOVAngle() == 180) {
		Subsystems::intake.release();
		if (Subsystems::guillotine.getLiftPosition() < 2160) {
			Subsystems::guillotine.setLiftSpeed(1.0f);
		} else {
			Subsystems::guillotine.setLiftSpeed(0.25f);
		}
	} else if (UserInterface::userInterface.controller.X.Get()) {
		Subsystems::intake.release();
		Subsystems::guillotine.setLiftSpeed(1.0f);
	} else if (UserInterface::userInterface.controller.Y.Get()) {
		Subsystems::guillotine.setLiftSpeed(-0.4f);
		if (Subsystems::guillotine.getLowerSwitchValue()) {
			Subsystems::guillotine.kick();
		}
	}
	Subsystems::intake.setArmsSpeed(0.0f);
	if (UserInterface::userInterface.controller.getLeftTrigger() > 0.1f) {
		Subsystems::intake.setArmsSpeed(0.3f, 0.5f);
	} else if (UserInterface::userInterface.controller.getRightTrigger() > 0.1f) {
		Subsystems::intake.setArmsSpeed(-0.45f);
	}
	Subsystems::intake.setPivotSpeed(0.0f);
	if (UserInterface::userInterface.controller.getLeftJoystickY() < -0.6f) {
		Subsystems::intake.setPivotSpeed(-UserInterface::userInterface.controller.getLeftJoystickY());
	} else if (UserInterface::userInterface.controller.getRightJoystickY() < -0.2f) {
		Subsystems::intake.setPivotSpeed(UserInterface::userInterface.controller.getRightJoystickY());
	}
	if (Subsystems::guillotine.getLowerSwitchValue()) {
		Subsystems::guillotine.zeroLiftPosition();
	}
	Scheduler::GetInstance()->Run();
	setRobotLightMode();
	printDataToSmartDashboard();
}

/**
 * Send any useful information to the SmartDashboard
 */
void Robot::printDataToSmartDashboard() {
	SmartDashboard::PutBoolean("Lift Upper Switch", Subsystems::guillotine.getUpperSwitchValue());
	SmartDashboard::PutBoolean("Lift Lower Switch", Subsystems::guillotine.getLowerSwitchValue());
	SmartDashboard::PutBoolean("Intake Upper Switch", Subsystems::intake.getUpperSwitchValue());
	SmartDashboard::PutBoolean("Intake Lower Switch", Subsystems::intake.getLowerSwitchValue());
	SmartDashboard::PutNumber("Guillotine Position", Subsystems::guillotine.getLiftPosition());
	SmartDashboard::PutNumber("Left Encoder", Subsystems::driveBase.getLeftPosition());
	SmartDashboard::PutNumber("Right Encoder", Subsystems::driveBase.getRightPosition());
	SmartDashboard::PutNumber("Left Arm Current", Subsystems::intake.getLeftArmCurrent());
	SmartDashboard::PutNumber("Right Arm Current", Subsystems::intake.getRightArmCurrent());
	SmartDashboard::PutNumber("Xbox POV", UserInterface::userInterface.controller.getPOVAngle());
	SmartDashboard::PutNumber("Gyro Angle", Subsystems::driveBase.getGyroAngle());
	SmartDashboard::PutNumber("blockX", pixyTable->GetNumber("blockX", 404));
	SmartDashboard::PutNumber("blockY", pixyTable->GetNumber("blockY", 404));
	SmartDashboard::PutNumber("blockW", pixyTable->GetNumber("blockW", 404));
	SmartDashboard::PutNumber("blockH", pixyTable->GetNumber("blockH", 404));
    SmartDashboard::PutNumber("blockCenterX", pixyTable->GetNumber("blockCenterX", 404));
    SmartDashboard::PutNumber("blockCenterY", pixyTable->GetNumber("blockCenterY", 404));
    SmartDashboard::PutNumber("blockArea", pixyTable->GetNumber("blockArea", 404));
    SmartDashboard::PutBoolean("active", pixyTable->GetBoolean("active", true));
    SmartDashboard::PutBoolean("Beam Break", Subsystems::driveBase.getBeamBreak());
    SmartDashboard::PutString("Target Type", pixyTable->GetString("target_type", "area"));
}

/**
 * Ensure the autonomous pointer is destroyed
 */
void Robot::destroyAutonomous() {
	if (autonomous != nullptr) {
		printf("Deleting the autonomous");
		autonomous->Cancel();
		Scheduler::GetInstance()->Remove(autonomous);
		delete autonomous;
		autonomous = nullptr;
	}
}

/**
 * Determines what the robot's lights should look like, then sends the data to the roboRIO
 */
void Robot::setRobotLightMode() {
	// Proportional lights, run only if not in the last 30 seconds of the match
	if (!isLast30Seconds) {
		// Copy the last position, then fetch the new position of the lift
		double lastGuillotinePosition = currentGuillotinePosition;
		currentGuillotinePosition = floor((double) ((double) Subsystems::guillotine.getLiftPosition()) / 72.0d);
		// If the positions are different, update the lights
		if (lastGuillotinePosition != currentGuillotinePosition) {
			std::string cmd = std::to_string((int) (currentGuillotinePosition / 30.0d * 255.0d));
			while (cmd.size() < 3) {
				cmd = "0" + cmd;
			}
			if (DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed) {
				Subsystems::arduino.sendCommand(cmd + "1332");
			} else {
				Subsystems::arduino.sendCommand(cmd + "1222");
			}
		}
	}
	// Only run once through, when it is the last 30 seconds of teleop
	if ((m_ds.GetMatchTime() < 30) && !isLast30Seconds) {
		if (DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed) {
			Subsystems::arduino.sendCommand("0003303");
		} else {
			Subsystems::arduino.sendCommand("0002203");
		}
		isLast30Seconds = !isLast30Seconds;
	}
}

START_ROBOT_CLASS(Robot);
