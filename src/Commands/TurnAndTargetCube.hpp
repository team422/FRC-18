#pragma once

#include <WPILib.h>

#include "../Util/Direction.hpp"

class TurnAndTargetCube : public frc::Command  {
public:
	TurnAndTargetCube(double speed, Direction defaultDirection, double timeout);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void Interrupted() override;
	void End() override;
private:
	double speed;
	Direction defaultDirection;
	bool done;
	std::shared_ptr<NetworkTable> pixyTable;
};
