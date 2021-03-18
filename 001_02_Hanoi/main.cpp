#include <iostream>
#include <vector>

#include "HanoiGame.h"
#include "ConsoleVisualHanoiMover.h"
#include "HanoiSolver.h"

int main() {
	//TextOutputHanoiMover mover{};
	HanoiGame game{ 3 };
	ConsoleVisualHanoiMover mover{ game };
	game.display_state();
	
	HanoiSolver solver(mover, 3);
	solver.solve();

	return 0;
}
