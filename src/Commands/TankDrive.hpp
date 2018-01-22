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

};
