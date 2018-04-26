#pragma once

#include <WPILib.h>

#include "../Util/Direction.hpp"

class DriveAndTargetCube : public frc::Command {
public:
    DriveAndTargetCube(double speed, Direction direction, double timeout);
    void Initialize();
    void Execute();
    bool IsFinished();
    void Interrupted();
    void End();
private:
    double speed;
    Direction direction;
	std::shared_ptr<NetworkTable> pixyTable;
};


