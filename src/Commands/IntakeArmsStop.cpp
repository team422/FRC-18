#include "IntakeArmsStop.hpp"
#include "../Subsystems/Subsystems.hpp"

IntakeArmsStop::IntakeArmsStop() {
	Requires(&Subsystems::intake);
}

void IntakeArmsStop::Initialize() {

}

void IntakeArmsStop::Execute() {
	Subsystems::intake.setArmsSpeed(0.0f);
}

bool IntakeArmsStop::IsFinished() {
	return true;
}

void IntakeArmsStop::Interrupted() {

}

void IntakeArmsStop::End() {

}

