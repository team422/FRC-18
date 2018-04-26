#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

class Guillotine: public frc::Subsystem {
public:
	Guillotine();
	void hold();
	void kick();
	void setLiftSpeed(double speed);
	bool getUpperSwitchValue();
	bool getLowerSwitchValue();
	int getLiftPosition();
	void zeroLiftPosition();
private:
	DoubleSolenoid kicker;
	TalonSRX lift;
	DigitalInput upperSwitch, lowerSwitch;
};

