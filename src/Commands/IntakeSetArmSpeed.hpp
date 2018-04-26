#pragma once

#include <WPILib.h>

class IntakeSetArmSpeed : public frc::Command {
public:
    IntakeSetArmSpeed(double speed);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void Interrupted() override;
    void End() override;
private:
    double speed;
};
