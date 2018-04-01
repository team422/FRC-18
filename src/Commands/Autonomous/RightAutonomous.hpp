#pragma once

#include "../Util/CommandBatch.hpp"

class RightAutonomous : public CommandBatch {
public:
	RightAutonomous(std::string gameData, bool scale);
};
