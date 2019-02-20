#include <iostream>
#include <vector>
#include <iterator>
#include <forward_list>

#define p 1000000007l
#define x 263

class HashTable
{
public:
	HashTable(unsigned size) : _size(size)  {
		_table.resize(size);
	}
	~HashTable() {}

	void		add(std::string str) {
		int index = hash(str);
		if (!_table[index].empty()) {
			auto i = _table[index].begin();
			while (i != _table[index].end()) {
				if (*i == str)
					return;
				++i;
			}
		}
		_table[index].push_front(str);
	}

	void		del(std::string str) {
		int index = hash(str);
		if (!_table[index].empty()) {
			auto i = _table[index].begin();
			if (*i == str) {
				_table[index].pop_front();
				return;
			}
			auto  prev = _table[index].begin();
			while (i != _table[index].end()) {
				if (*i == str) {
					_table[index].erase_after(prev);
					return;
				}
				prev = i;
				++i;
			}
		}
	}

	void		find(std::string str) {

		int index = hash(str);
		if (!_table[index].empty()) {
			auto i = _table[index].begin();
			while (i != _table[index].end()) {
				if (*i == str) {
					std::cout << "yes" << std::endl;
					return;
				}
				++i;
			}
		}
		std::cout << "no" << std::endl;
	}
	void		check(int number) {
		if (number < _size && !_table[number].empty())
			for (auto i : _table[number])
				std::cout << i << " ";
		std::cout << std::endl;
	}

private:
	
	long long	pow(long long base, size_t power) {
		long long res = 1;
		if (power == 0)
			return 1;
		for (int i = 0; i < power; ++i) {
			res *= base;
			res %= p;
		}
		return res;
	}

	int			hash(std::string str) {
		size_t len = str.length();
		size_t i = 0;
		long long res = 0;
		long long tmp;

		while (i < len) {
			tmp = str[i]  * pow(x, i);
			res += tmp;
			++i;
		}
		res %= p;
		res %= _size;
		return (int)res;
	}

	unsigned									_size;
	std::vector<std::forward_list<std::string>>	_table;
};

int		main(void)
{
	unsigned tableSize, numRequests;
	std::string		command;
	std::string		argument;
	int 			number;

	std::cin >> tableSize >> numRequests;

	HashTable		table(tableSize);

	for (int i = 0; i <numRequests; ++i) {
		std::cin >> command;
		if (command == "add") {
			std::cin >> argument;
			table.add(argument);
		}
		else if (command == "del") {
			std::cin >> argument;
			table.del(argument);
		}
		else if (command == "find") {
			std::cin >> argument;
			table.find(argument);
		}
		else if (command == "check") {
			std::cin >> number;
			table.check(number);
		}
	}
	return 0;
}