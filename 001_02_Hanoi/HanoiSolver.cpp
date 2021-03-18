#include "HanoiSolver.h"

void HanoiSolver::move_tower(int from, int to, int n) {
	// Calculate stacker index (Zwischenablage)
	int stacker = 3 - from - to;

	// Trivial case: Move only one disk
	if (n == 1) {
		//std::cout << "Moving disk from " << from + 1 << " to " << to + 1 << std::endl;
		m_mover.move(from, to);
		return;
	}

	// Move (recursively) 
	move_tower(from, stacker, n - 1);
	move_tower(from, to, 1);
	move_tower(stacker, to, n - 1);
}
