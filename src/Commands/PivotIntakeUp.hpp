#pragma once

#include <WPILib.h>

class PivotIntakeUp: public frc::Command {
public:
	PivotIntakeUp(bool forTimeOnly, float time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	bool forTimeOnly;
	float time;
};

