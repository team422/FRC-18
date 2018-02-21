#pragma once

#include <WPILib.h>
#include <ctre/Phoenix.h>

class Guillotine: public frc::Subsystem {
public:
	Guillotine();
	virtual ~Guillotine();
	void hold();
	void kick();
	void raiseLift();
	void lowerLift();
	void stopLift();
	bool getUpperSwitchValue();
	bool getLowerSwitchValue();
private:
	DoubleSolenoid kicker;
	TalonSRX lift;
	DigitalInput upperSwitch, lowerSwitch;
};

