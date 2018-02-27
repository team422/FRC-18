#include "IntakeArmsOut.hpp"
#include "../Subsystems/Subsystems.hpp"

IntakeArmsOut::IntakeArmsOut() {
	Requires(&Subsystems::intake);
}

void IntakeArmsOut::Initialize() {

}

void IntakeArmsOut::Execute() {
	Subsystems::intake.setArmsSpeed(-0.4f);
}

bool IntakeArmsOut::IsFinished() {
	return true;
}

void IntakeArmsOut::Interrupted() {

}

void IntakeArmsOut::End() {

}

