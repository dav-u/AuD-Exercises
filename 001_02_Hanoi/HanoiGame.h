#pragma once
#include <vector>
#include "HanoiTower.h"

class HanoiGame {
private:
	std::vector<HanoiTower> m_towers{};
	int m_disk_count;

public:
	HanoiGame(int disk_count);

	int get_disk_count() {
		return m_disk_count;
	}

	void move(int from_index, int to_index);

	void display_state();

private:
	void draw_disk(std::size_t disk_value);

	void draw_stick();
};