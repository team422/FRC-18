#pragma once

#include <WPILib.h>

class Turn : public frc::Command  {
public:
	Turn(double degrees, double speed, double timeout);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
private:
	double degrees;
	double speed;
	bool isCorrecting;
};
