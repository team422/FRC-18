#include "RightAutonomous.hpp"

#include "../../UserInterface/UI.hpp"
#include "../ArduinoControllerSendCommand.hpp"
#include "../DriveAndTargetCube.hpp"
#include "../DriveStraight.hpp"
#include "../GuillotineHold.hpp"
#include "../GuillotineKick.hpp"
#include "../GuillotineLower.hpp"
#include "../GuillotineRaise.hpp"
#include "../IntakeBox.hpp"
#include "../IntakeGrab.hpp"
#include "../IntakePivot.hpp"
#include "../IntakeRelease.hpp"
#include "../IntakeSetArmSpeed.hpp"
#include "../Turn.hpp"

RightAutonomous::RightAutonomous(std::string gameData, bool scale) {
    AddSequential(new GuillotineHold());
    AddSequential(new IntakeGrab());
    if (gameData[1] == 'R' && scale && UserInterface::userInterface.launchpad.getSwitch4()) {
        // Two-Cube Auto
        AddSequential(new DriveStraight(156.0f, 0.9f, Direction::FORWARD, 8.0f));
        AddSequential(new Turn(-25.0f, 0.7f, 3.0f));
        AddSequential(new IntakeRelease());
        AddParallel(new DriveStraight(70.0f, 0.9f, Direction::FORWARD, 6.0f));
        AddSequential(new GuillotineRaise());
        AddParallel(new GuillotineKick());
        AddSequential(new DriveStraight(36.0f, 0.9f, Direction::REVERSE, 0.25f));
        AddSequential(new GuillotineLower());
//        AddParallel(new IntakePivot(Direction::DOWN, false, 1.0d));
//        AddSequential(new Turn(-156.0f, 0.7f, 2.0f));
//        if (gameData[0] == 'R' && UserInterface::userInterface.launchpad.getSwitch3()) {
//            // Two-Cube Scale then Switch Auto
//            AddParallel(new IntakeSetArmSpeed(0.8d));
//            AddSequential(new DriveAndTargetCube(0.40d, Direction::FORWARD, 5.0d));
//            AddSequential(new WaitCommand(0.5d));
//            AddSequential(new IntakeGrab());
//            AddSequential(new DriveStraight(18.0d, 0.9d, Direction::REVERSE, 1.0d));
//            AddSequential(new WaitCommand(0.1d));
//            AddSequential(new IntakeSetArmSpeed(0.0d));
//            AddSequential(new IntakePivot(Direction::UP, false, 1.5d));
//            AddSequential(new IntakePivot(Direction::UP, true, 0.05d));
//            AddSequential(new DriveStraight(18.0d, 0.9d, Direction::FORWARD, 0.5d));
//            AddSequential(new Turn(7.5f, 0.7f, 1.0f));
//            AddSequential(new IntakePivot(Direction::DOWN, false, 0.2f));
//            AddSequential(new IntakeSetArmSpeed(-0.8d));
//            AddSequential(new ArduinoControllerSendCommand());
//            AddSequential(new WaitCommand(4));
//            AddSequential(new IntakeSetArmSpeed(0.0d));
//        } else {
//            // Two-Cube Scale Auto
//            AddParallel(new IntakeSetArmSpeed(0.8d));
//            AddSequential(new DriveAndTargetCube(0.40d, Direction::FORWARD, 5.0d));
//            AddSequential(new WaitCommand(0.5d));
//            AddSequential(new IntakeGrab());
//            AddSequential(new DriveStraight(18.0d, 0.9d, Direction::REVERSE, 1.0d));
//            AddSequential(new WaitCommand(0.1d));
//            AddSequential(new IntakeSetArmSpeed(0.0d));
//            AddSequential(new IntakeBox());
//            AddParallel(new GuillotineRaise());
//            AddSequential(new Turn(150.0d, 0.7d, 2.0d));
//            AddSequential(new DriveStraight(48.0d, 0.6d, Direction::FORWARD, 4.0d));
//            AddSequential(new WaitCommand(0.2d));
//            AddSequential(new GuillotineKick());
//        }
    } else if (gameData[1] == 'R' && scale) {
        // Single Cube Scale Auto
        AddSequential(new DriveStraight(260.975f, 0.9f, Direction::FORWARD, 8.0f));
        AddSequential(new Turn(-94, 0.7f, 3.0f));
        AddSequential(new IntakeRelease());
        AddParallel(new DriveStraight(8, 0.5f, Direction::REVERSE, 0.6f));
        AddSequential(new GuillotineRaise());
        AddSequential(new DriveStraight(18, 0.8f, Direction::FORWARD, 1.5f));
        AddSequential(new GuillotineKick());
        AddSequential(new ArduinoControllerSendCommand());
        AddSequential(new DriveStraight(16, 0.5f, Direction::REVERSE, 1.5f));
        AddParallel(new GuillotineLower());
        AddParallel(new IntakePivot(Direction::DOWN, false, 0.75d));
    } else if (gameData[1] == 'L' && scale && !UserInterface::userInterface.launchpad.getSwitch2()) {
        // Opposite side scale auto
        // If switch 2 is up, disable this mode
        AddSequential(new DriveStraight(190.438, 0.9, Direction::FORWARD, 5.0d));
        AddSequential(new Turn(-87.0f, 0.7, 5.0d));
        AddSequential(new DriveStraight(140.625, 0.9, Direction::FORWARD, 5.0d));
        AddSequential(new Turn(98.0f, 0.7, 3.0d));
        AddParallel(new IntakeRelease());
        AddSequential(new GuillotineRaise());
        AddSequential(new DriveStraight(52.057, 0.5, Direction::FORWARD, 0.9f));
        AddSequential(new GuillotineKick());
        AddSequential(new ArduinoControllerSendCommand());
        AddSequential(new DriveStraight(16, 0.3f, Direction::REVERSE, 1.5f));
    } else if (gameData[0] == 'R') {
        // Right-side switch
        AddSequential(new DriveStraight(114.275f, 0.9f, Direction::FORWARD, 6.0f));
        AddSequential(new Turn(-90.0f, 0.7f, 3.0f));
        AddSequential(new DriveStraight(24.0f, 0.4f, Direction::FORWARD, 1.0f));
        AddSequential(new GuillotineKick());
        AddSequential(new IntakePivot(Direction::DOWN, false, 0.2f));
        AddSequential(new IntakeSetArmSpeed(-0.4d));
        AddSequential(new ArduinoControllerSendCommand());
        AddSequential(new WaitCommand(4));
        AddSequential(new IntakeSetArmSpeed(0.0d));
    } else {
        // Left-side switch
        AddSequential(new DriveStraight(187.53, 0.9f, Direction::FORWARD, 8.0f));
        AddSequential(new Turn(-90.0f, 0.7f, 3.0f));
        AddSequential(new DriveStraight(187.534, 0.9f, Direction::FORWARD, 1.5f));
        AddSequential(new Turn(-90, 0.7f, 3.0f));
        AddSequential(new DriveStraight(42.0f, 0.3f, Direction::FORWARD, 1.0f));
        AddSequential(new GuillotineKick());
        AddSequential(new IntakePivot(Direction::DOWN, false, 0.1f));
        AddSequential(new IntakeSetArmSpeed(-0.4d));
        AddSequential(new ArduinoControllerSendCommand());
        AddSequential(new WaitCommand(3));
        AddSequential(new IntakeSetArmSpeed(0.0d));
    }
}
