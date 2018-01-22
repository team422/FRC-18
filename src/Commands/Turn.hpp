#pragma once

#include <WPILib.h>

class Turn : public frc::Command  {
public:
	Turn(int degrees, float speed, float timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void Interrupted();
	void End();
private:
	int degrees;
	float speed;
	float timeout;
};
