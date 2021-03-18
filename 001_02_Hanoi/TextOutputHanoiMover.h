#pragma once
#include "HanoiMover.h"

class TextOutputHanoiMover : public HanoiMover {
public:
	void move(int from_index, int to_index) override {
		std::cout << "Moving disk from " << from_index + 1 << " to " << to_index + 1 << std::endl;
	}
};