#include "IntakeArmsIn.hpp"
#include "../Subsystems/Subsystems.hpp"

IntakeArmsIn::IntakeArmsIn() {
	Requires(&Subsystems::intake);
}

void IntakeArmsIn::Initialize() {

}

void IntakeArmsIn::Execute() {
	Subsystems::intake.setArmsSpeed(0.4f);
}

bool IntakeArmsIn::IsFinished() {
	return true;
}

void IntakeArmsIn::Interrupted() {

}

void IntakeArmsIn::End() {

}

