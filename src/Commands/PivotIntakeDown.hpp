#pragma once

#include <WPILib.h>

class PivotIntakeDown: public frc::Command {
public:
	PivotIntakeDown(float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	float time;
};

