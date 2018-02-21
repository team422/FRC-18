#pragma once

#include <WPILib.h>

class PivotIntakeUp: public frc::Command {
public:
	PivotIntakeUp(float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	float time;
};

