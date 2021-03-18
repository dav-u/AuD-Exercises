#pragma once
#include "HanoiMover.h"
#include "HanoiGame.h"

class ConsoleVisualHanoiMover : public HanoiMover {
private:
	HanoiGame& m_game;

public:
	ConsoleVisualHanoiMover(HanoiGame& game)
		: m_game(game) { }

	void move(int from_index, int to_index) override {
		m_game.move(from_index, to_index);
		m_game.display_state();
	}
};
