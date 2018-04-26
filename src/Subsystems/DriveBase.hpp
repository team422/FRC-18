#pragma once

#include "../Commands/TankDrive.hpp"
#include <WPILib.h>
#include <ctre/Phoenix.h>
#include "../RobotMap.h"

class DriveBase : public frc::Subsystem {
public:
	DriveBase();
	void setMotors(double left, double right);
	int getLeftPosition();
	int getRightPosition();
	int getLeftVelocity();
	int getRightVelocity();
	void InitDefaultCommand();
	double getGyroAngle();
	void zeroEncoderPosition();
	void zeroGyroAngle();
	bool getBeamBreak();
private:
	TalonSRX	leftMasterMotor,
				rightMasterMotor;
#ifdef COMP_BOT
	VictorSPX
#else
	TalonSRX
#endif
		leftFollower1,
		leftFollower2,
		rightFollower1,
		rightFollower2;
	DigitalInput beamBreak;
	TankDrive tankDrive;
	ADXRS450_Gyro gyro;
};
