#pragma once
#include <vector>

struct HanoiDisk {
private:
	int m_value;
public:
	HanoiDisk(int value) : m_value(value) { }
	
	int get_value() const {
		return m_value;
	}
};

class HanoiTower {
	std::vector<HanoiDisk> m_disks{};
public:
	//HanoiTower(const HanoiTower&) = delete;
	const std::vector<HanoiDisk>& get_disks() const {
		return m_disks;
	}

	std::size_t get_disk_count() const {
		return m_disks.size();
	}

	void emplace_disk(int value) {
		m_disks.emplace_back(value);
	}

	void emplace_disk(const HanoiDisk& disk) {
		m_disks.emplace_back(disk);
	}

	HanoiDisk pop_top() {
		HanoiDisk disk = m_disks.back();
		m_disks.pop_back();
		return disk;
	}
};