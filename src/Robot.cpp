#include "Robot.hpp"
#include "Commands/IntakeBox.hpp"
#include "Commands/PivotIntakeDown.hpp"
#include "Commands/PivotIntakeUp.hpp"
#include "Commands/IntakeGrab.hpp"
#include "Commands/IntakeRelease.hpp"
#include "Commands/GuillotineHold.hpp"
#include "Commands/GuillotineKick.hpp"
#include "UserInterface/UI.hpp"
#include <cmath>

void Robot::RobotInit() {
	Subsystems::compressor.Start();
	UserInterface::userInterface.controller.A.WhenPressed(new IntakeGrab());
	UserInterface::userInterface.controller.B.WhenPressed(new IntakeRelease());
	UserInterface::userInterface.controller.LB.WhenPressed(new GuillotineHold());
	UserInterface::userInterface.controller.RB.WhenPressed(new GuillotineKick());
	UserInterface::userInterface.controller.START.WhenPressed(new IntakeBox());
	camera = CameraServer::GetInstance()->StartAutomaticCapture();
	Subsystems::arduino.sendCommand("0001111");
	Subsystems::guillotine.zeroLiftPosition();
	currentGuillotinePosition = floor((double) ((double) Subsystems::guillotine.getLiftPosition()) / 20.0d);
	SmartDashboard::PutString("Auto State", "Destroyed");
	isLast30Seconds = false;
}

void Robot::DisabledInit() {
	Subsystems::arduino.sendCommand("0001111");
	destroyAutonomous();
}

void Robot::DisabledPeriodic() {
	printDataToSmartDashboard();
}

void Robot::AutonomousInit() {
	Subsystems::arduino.sendCommand("0005551");
	std::string gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if (UserInterface::userInterface.launchpad.getMultiSwitchLeft()) {
		autonomous = new LeftAutonomous(gameData, UserInterface::userInterface.launchpad.getSwitch1());
	} else if (UserInterface::userInterface.launchpad.getMultiSwitchInactive()) {
		autonomous = new CenterAutonomous(gameData[0]);
	} else if (UserInterface::userInterface.launchpad.getMultiSwitchRight()) {
		autonomous = new RightAutonomous(gameData, UserInterface::userInterface.launchpad.getSwitch1());
	}
	SmartDashboard::PutString("Auto State", "Initialized");
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
	// Proportional lights
	if (!isLast30Seconds) {
		double lastGuillotinePosition = currentGuillotinePosition;
		currentGuillotinePosition = floor((double) ((double) Subsystems::guillotine.getLiftPosition()) / 72.0d);
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
	// Only run once through
	if ((m_ds.GetMatchTime() < 30) && !isLast30Seconds) {
		if (DriverStation::GetInstance().GetAlliance() == DriverStation::Alliance::kRed) {
			Subsystems::arduino.sendCommand("0003303");
		} else {
			Subsystems::arduino.sendCommand("0002203");
		}
		isLast30Seconds = !isLast30Seconds;
	}
	printDataToSmartDashboard();
}

void Robot::printDataToSmartDashboard() {
	SmartDashboard::PutNumber("Ultrasonic", Subsystems::intake.getUltrasonicDistance());
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
}

void Robot::destroyAutonomous() {
	if (autonomous != nullptr) {
		printf("Deleting the autonomous");
		autonomous->Cancel();
		Scheduler::GetInstance()->Remove(autonomous);
		delete autonomous;
		autonomous = nullptr;
		SmartDashboard::PutString("Auto State", "Destroyed");
	}
}

START_ROBOT_CLASS(Robot);
