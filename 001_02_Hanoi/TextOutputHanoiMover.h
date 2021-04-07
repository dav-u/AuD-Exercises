#pragma once
#include "HanoiMover.h"

class TextOutputHanoiMover : public HanoiMover {
private:
	int m_move_count = 0;
public:
	void move(int from_index, int to_index) override {
		m_move_count++;
		std::cout << "Moving disk from " << from_index + 1 << " to " << to_index + 1 << std::endl;
	}
	void displayMoveCount() {
		std::cout << "Took " << m_move_count << " moves" << std::endl;
	}
};