#include "IntakeArmsOut.hpp"
#include "../Subsystems/Subsystems.hpp"

IntakeArmsOut::IntakeArmsOut() {
	Requires(&Subsystems::intake);
}

void IntakeArmsOut::Initialize() {

}

void IntakeArmsOut::Execute() {
	Subsystems::intake.setArmsOut();
}

bool IntakeArmsOut::IsFinished() {
	return true;
}

void IntakeArmsOut::Interrupted() {
	Cancel();
}

void IntakeArmsOut::End() {

}

