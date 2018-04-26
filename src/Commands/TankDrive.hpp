#pragma once

#include <WPILib.h>

class TankDrive : public frc::Command {
public:
	TankDrive();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
private:
	double leftSpeed, rightSpeed;
	const double MAX_CHANGE = 0.08f;
};
