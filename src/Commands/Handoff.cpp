#include "Handoff.hpp"
#include "IntakeBox.hpp"
#include "IntakeRelease.hpp"
#include "GuillotineScore.hpp"


Handoff::Handoff() {
	AddSequential(new IntakeBox());
	AddSequential(new IntakeRelease());
	AddSequential(new WaitCommand(0.5f));
	AddSequential(new GuillotineScore());
}

