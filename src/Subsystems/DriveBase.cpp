#include "DriveBase.hpp"

DriveBase::DriveBase() :
	Subsystem("DriveBase"),
	leftMasterMotor(Ports::LEFT_MASTER_MOTOR),
	rightMasterMotor(Ports::RIGHT_MASTER_MOTOR),
	leftFollower1(Ports::LEFT_FOLLOWER_1),
	leftFollower2(Ports::LEFT_FOLLOWER_2),
	rightFollower1(Ports::RIGHT_FOLLOWER_1),
	rightFollower2(Ports::RIGHT_FOLLOWER_2) {
		leftFollower1.SetInverted(true);
		leftMasterMotor.SetInverted(true);
		leftFollower2.SetInverted(true);

		leftFollower1.Follow(leftMasterMotor);
		leftFollower2.Follow(leftMasterMotor);
		rightFollower1.Follow(rightMasterMotor);
		rightFollower2.Follow(rightMasterMotor);

		leftMasterMotor.SetSensorPhase(true);
		rightMasterMotor.SetSensorPhase(true);
}

void DriveBase::setMotors(float left, float right) {
	leftMasterMotor.Set(ControlMode::PercentOutput, left);
	rightMasterMotor.Set(ControlMode::PercentOutput, right);
}

int DriveBase::getLeftPosition() {
	return leftMasterMotor.GetSelectedSensorPosition(0);
}
int DriveBase::getRightPosition() {
	return rightMasterMotor.GetSelectedSensorPosition(0);
}

int DriveBase::getLeftVelocity() {
	return leftMasterMotor.GetSelectedSensorVelocity(0);
}

int DriveBase::getRightVelocity() {
	return rightMasterMotor.GetSelectedSensorVelocity(0);
}

void DriveBase::InitDefaultCommand() {
	SetDefaultCommand(&tankDrive);
}

float DriveBase::getGyroAngle() {
	return gyro.GetAngle();
}

void DriveBase::zeroEncoderPosition() {
	leftMasterMotor.SetSelectedSensorPosition(0,0,10);
	rightMasterMotor.SetSelectedSensorPosition(0,0,10);
}

void DriveBase::zeroGyroAngle() {
	gyro.Reset();
}
