#include "GuillotineScore.hpp"
#include "IntakeRelease.hpp"
#include "GuillotineHold.hpp"
#include "GuillotineRaise.hpp"
#include "GuillotineLower.hpp"
#include "GuillotineKick.hpp"

GuillotineScore::GuillotineScore() {
	AddSequential(new IntakeRelease());
	AddSequential(new GuillotineHold());
	AddSequential(new GuillotineRaise());
	AddSequential(new WaitCommand(0.5));
	AddSequential(new GuillotineKick());
	AddSequential(new WaitCommand(0.5));
	AddSequential(new GuillotineLower());
}

