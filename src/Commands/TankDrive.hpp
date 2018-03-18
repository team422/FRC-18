#pragma once

#include <WPILib.h>

class TankDrive : public frc::Command {
public:
	TankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	float leftSpeed, rightSpeed;
	const float MAX_CHANGE = 0.08f;
};
