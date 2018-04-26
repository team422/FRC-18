#pragma once

#include <WPILib.h>

#include "../Util/Direction.hpp"

// TODO This will replace the PivotUp and PivotDown commands
class IntakePivot : public frc::Command {
public:
    IntakePivot(Direction direction, bool useTimeoutOnly, double timeout);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void Interrupted() override;
    void End() override;
private:
    Direction direction;
    bool useTimeoutOnly;
};


