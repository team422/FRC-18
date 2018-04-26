#include "DriveBase.hpp"

/**
 * Represents one instance of the Drive Base
 *
 * This contains the motor controllers and any sensors that are connected to the drive base.
 */
DriveBase::DriveBase() :
	Subsystem("DriveBase"),
	leftMasterMotor(Ports::LEFT_MASTER_MOTOR),
	rightMasterMotor(Ports::RIGHT_MASTER_MOTOR),
	leftFollower1(Ports::LEFT_FOLLOWER_1),
	leftFollower2(Ports::LEFT_FOLLOWER_2),
	rightFollower1(Ports::RIGHT_FOLLOWER_1),
	rightFollower2(Ports::RIGHT_FOLLOWER_2),
	beamBreak(Ports::BEAM_BREAK) {
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

/**
 * Sets the motor speeds for the left and right motors
 * @param left 	The speed of the left side
 * @param right The speed of the right side
 */
void DriveBase::setMotors(double left, double right) {
	leftMasterMotor.Set(ControlMode::PercentOutput, left * 0.8f);
	rightMasterMotor.Set(ControlMode::PercentOutput, right * 0.8f);
}

/**
 * Gets the left encoder position
 * @return The left encoder position
 */
int DriveBase::getLeftPosition() {
	return leftMasterMotor.GetSelectedSensorPosition(0);
}

/**
 * Gets the right encoder position
 * @return The right encoder position
 */
int DriveBase::getRightPosition() {
	return rightMasterMotor.GetSelectedSensorPosition(0);
}

/**
 * Gets the left encoder velocity
 * @return The left encoder velocity
 */
int DriveBase::getLeftVelocity() {
	return leftMasterMotor.GetSelectedSensorVelocity(0);
}

/**
 * Gets the right encoder velocity
 * @return The right encoder velocity
 */
int DriveBase::getRightVelocity() {
	return rightMasterMotor.GetSelectedSensorVelocity(0);
}

/**
 * Sets the default command of this subsystems
 */
void DriveBase::InitDefaultCommand() {
	SetDefaultCommand(&tankDrive);
}

/**
 * Gets the gyroscope angle
 * @return The gyro angle
 */
double DriveBase::getGyroAngle() {
	return gyro.GetAngle();
}

/**
 * Sets the encoder positions on both the left and right to zero
 */
void DriveBase::zeroEncoderPosition() {
	leftMasterMotor.SetSelectedSensorPosition(0, 0, 10);
	leftMasterMotor.GetSensorCollection().SetQuadraturePosition(0, 10);
	rightMasterMotor.SetSelectedSensorPosition(0, 0, 10);
	rightMasterMotor.GetSensorCollection().SetQuadraturePosition(0, 10);
}

/**
 * Resets the gyro to an angle of zero
 */
void DriveBase::zeroGyroAngle() {
	gyro.Reset();
}

/**
 * Gets whether or not the beam break sensor is activated
 * @return	A boolean representing the state of the beam break sensor
 */
bool DriveBase::getBeamBreak() {
	return !beamBreak.Get();
}
