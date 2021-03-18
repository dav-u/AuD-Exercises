#pragma once
#include "HanoiMover.h"

class HanoiSolver {
private:
	int m_disk_count;
	HanoiMover& m_mover;

public:
	HanoiSolver(HanoiMover& mover, int disk_count)
		: m_mover(mover), m_disk_count(disk_count) { }

	void solve() {
		move_tower(0, 2, m_disk_count);
	}

private:
	void move_tower(int from, int to, int n);
};
