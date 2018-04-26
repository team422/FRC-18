#include "IntakeBox.hpp"

#include "../Util/Direction.hpp"
#include "GuillotineHold.hpp"
#include "GuillotineKick.hpp"
#include "IntakeGrab.hpp"
#include "IntakePivot.hpp"

/**
 * A routine that will take a box grabbed by the intake, and bring it up into the lift
 *
 * The kicker on the guillotine is closed when the box reaches it. This automation is used
 * to reduce the error of having the operator close the kicker
 */
IntakeBox::IntakeBox() {
    AddParallel(new IntakeGrab());
    AddSequential(new GuillotineKick());
    AddSequential(new WaitCommand(0.1d));
    AddSequential(new IntakePivot(Direction::UP, false, 1.5d));
    AddSequential(new IntakePivot(Direction::UP, true, 0.05d));
    AddSequential(new WaitCommand(0.25f));
    AddSequential(new GuillotineHold());
}

