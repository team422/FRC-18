#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

#include "../RobotMap.h"

class Intake : public frc::Subsystem {
public:
	Intake();
	void stopArms();
	void setArmsIn();
	void setArmsOut();
	void grab();
	void release();
	void stopPivot();
	void pivotUp();
	void pivotDown();
	void setPivotSpeed(float speed);
	bool getUpperSwitchValue();
	bool getLowerSwitchValue();
	bool getBeamBrakeValue();
	float getLeftArmCurrent();
	float getRightArmCurrent();
	float getUltrasonicDistance();
private:
	DoubleSolenoid grabber;
	TalonSRX pivot, leftArm, rightArm;
	DigitalInput upperSwitch, lowerSwitch;
	AnalogInput ultrasonic;
	bool isIntaking;
};
