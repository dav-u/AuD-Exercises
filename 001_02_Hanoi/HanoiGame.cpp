#include <iostream>
#include <string>
#include "HanoiGame.h"

HanoiGame::HanoiGame(int disk_count) : m_disk_count(disk_count) {
	m_towers.emplace_back();
	m_towers.emplace_back();
	m_towers.emplace_back();

	for (int i = disk_count; i > 0; i--)
		m_towers[0].emplace_disk(i);
}

void HanoiGame::move(int from_index, int to_index) {
	HanoiDisk disk = m_towers[from_index].pop_top();
	m_towers[to_index].emplace_disk(disk);
}

void HanoiGame::display_state() {
	struct TowerIterator {
		std::vector<HanoiDisk>::const_reverse_iterator iterator;
		std::size_t disk_count;
	};

	std::vector<TowerIterator> iterators;

	for (const HanoiTower& tower : m_towers)
		iterators.push_back({ tower.get_disks().rbegin(), tower.get_disk_count() });

	for (int i = 0; i < m_disk_count; i++) {
		for (TowerIterator& tower_it : iterators) {
			if (i < m_disk_count - tower_it.disk_count) {
				draw_stick();
				continue;
			}

			int disk_value = tower_it.iterator->get_value();
			draw_disk(disk_value);
			tower_it.iterator++;
		}
		std::cout << std::endl;
	}

	std::string line(m_towers.size() * (2 * std::size_t(m_disk_count) + 3), '-');
	std::cout << line << "\n\n";
}

void HanoiGame::draw_disk(std::size_t disk_value) {
	std::string spaces(m_disk_count - disk_value + 1, ' ');
	std::string hashes(2 * disk_value + 1, '#');

	std::cout << spaces << hashes << spaces;
}

void HanoiGame::draw_stick() {
	std::string spaces(std::size_t(m_disk_count) + 1, ' ');
	std::cout << spaces << '|' << spaces;
}
