#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

#include "../RobotMap.h"

class Intake : public frc::Subsystem {
public:
	Intake();
	void setArmsSpeed(double speed);
	void setArmsSpeed(double left, double right);
	void grab();
	void release();
	void setPivotSpeed(double speed);
	bool getUpperSwitchValue();
	bool getLowerSwitchValue();
	bool getBeamBrakeValue();
	double getLeftArmCurrent();
	double getRightArmCurrent();
	double getUltrasonicDistance();
private:
	DoubleSolenoid grabber;
	TalonSRX pivot, leftArm, rightArm;
	DigitalInput upperSwitch, lowerSwitch;
};
