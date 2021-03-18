#include <iostream>
#include <vector>

class Output {
public:
	virtual void put(unsigned int n) = 0;
};

class ConsoleOutput : public Output {
private:
	bool m_is_first_num = true;
public:
	void put(unsigned int n) override {
		if (m_is_first_num) {
			std::cout << n;
			m_is_first_num = false;
		}
		else std::cout << ", " << n;
	}

	void reset() {
		std::cout << std::endl;
		m_is_first_num = true;
	}
};

class CollectorOutput : public Output {
private:
	std::vector<unsigned int> m_data{};

public:
	void put(unsigned int n) override {
		m_data.push_back(n);
	}

	const std::vector<unsigned int>& get_data() const {
		return m_data;
	}
};

void collatz(unsigned int n, Output& output) {
	if (n == 0) return;

	while (n != 1) {
		output.put(n);
		if (n % 2 == 0)
			n = n / 2;
		else n = 3 * n + 1;
	}

	output.put(n);
}

int main() {
	ConsoleOutput co;

	collatz(27, co);
	co.reset();
	std::cout << "---------------------------------------------\n";

	collatz(37, co);
	co.reset();
	std::cout << "---------------------------------------------\n";

	collatz(42, co);
	co.reset();

	return 0;
}
