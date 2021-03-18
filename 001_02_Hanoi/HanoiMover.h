#pragma once

class HanoiMover {
public:
	virtual void move(int from_index, int to_index) = 0;
};