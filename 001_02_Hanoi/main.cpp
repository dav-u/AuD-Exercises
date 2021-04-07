#include <iostream>
#include <vector>

#include "HanoiGame.h"
#include "ConsoleVisualHanoiMover.h"
#include "TextOutputHanoiMover.h"
#include "HanoiSolver.h"

int main() {
	//TextOutputHanoiMover mover{};
	HanoiGame game{ 5 };
	ConsoleVisualHanoiMover mover{ game };
	game.display_state();
	
	HanoiSolver solver(mover, game.get_disk_count());
	solver.solve();
	//mover.displayMoveCount();

	return 0;
}
