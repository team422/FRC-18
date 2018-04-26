#include "CommandBatch.hpp"

/**
 * Like a command group, but stores a pointer to each command added to be deleted later
 */
CommandBatch::CommandBatch() {
	commands.clear();
}

CommandBatch::~CommandBatch() {
	printf("Killing Command Batch");
	for (Command *command : commands) {
		delete command;
	}
}

void CommandBatch::AddSequential(Command *command) {
	commands.push_back(command);
	CommandGroup::AddSequential(command);
}

void CommandBatch::AddSequential(Command *command, double timeout) {
	commands.push_back(command);
	CommandGroup::AddSequential(command, timeout);
}

void CommandBatch::AddParallel(Command *command) {
	commands.push_back(command);
	CommandGroup::AddParallel(command);
}

void CommandBatch::AddParallel(Command *command, double timeout) {
	commands.push_back(command);
	CommandGroup::AddParallel(command, timeout);
}
