#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

class Guillotine: public frc::Subsystem {
public:
	Guillotine();
	void hold();
	void kick();
	void setLiftSpeed(float speed);
	bool getUpperSwitchValue();
	bool getLowerSwitchValue();
	int getLiftPosition();
private:
	DoubleSolenoid kicker;
	TalonSRX lift;
	DigitalInput upperSwitch, lowerSwitch;
};

