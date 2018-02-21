#include "IntakeArmsStop.hpp"
#include "../Subsystems/Subsystems.hpp"

IntakeArmsStop::IntakeArmsStop() {
	Requires(&Subsystems::intake);
}

void IntakeArmsStop::Initialize() {

}

void IntakeArmsStop::Execute() {
	Subsystems::intake.stopArms();
}

bool IntakeArmsStop::IsFinished() {
	return true;
}

void IntakeArmsStop::Interrupted() {

}

void IntakeArmsStop::End() {

}

