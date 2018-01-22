#include "Robot.hpp"

void Robot::AutonomousInit() {
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	if(gameData[0] == 'R')
	{
		(new Turn(180,0.2,10))->Start();
	} else {
		(new Turn(90,0.2,5))->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Angle", Subsystems::driveBase.getGyroAngle());
	SmartDashboard::PutNumber("Left Position", Subsystems::driveBase.getLeftPosition());
	SmartDashboard::PutNumber("Left Velocity", Subsystems::driveBase.getLeftVelocity());
	SmartDashboard::PutNumber("Right Position", Subsystems::driveBase.getRightPosition());
	SmartDashboard::PutNumber("Right Velocity", Subsystems::driveBase.getRightVelocity());
}

void Robot::TeleopInit() {

}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Angle", Subsystems::driveBase.getGyroAngle());
	SmartDashboard::PutNumber("Left Position", Subsystems::driveBase.getLeftPosition());
	SmartDashboard::PutNumber("Left Velocity", Subsystems::driveBase.getLeftVelocity());
	SmartDashboard::PutNumber("Right Position", Subsystems::driveBase.getRightPosition());
	SmartDashboard::PutNumber("Right Velocity", Subsystems::driveBase.getRightVelocity());
}

START_ROBOT_CLASS(Robot);
