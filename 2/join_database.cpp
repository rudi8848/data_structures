#include <iostream>
#include <vector>

class Database
{
public:
	Database(unsigned numTables) {
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		_tables.resize(numTables + 1);
		_rank.resize(numTables + 1);
		_parent.resize(numTables + 1);
		_maxSize = 0;
		for (int i = 1; i < numTables + 1; ++i) {
			std::cin >> _tables[i];
			if (_tables[i] > _maxSize)
				_maxSize = _tables[i];
			makeSet(i);
		}
	}
	~Database(){}
	
	void	join(unsigned i, unsigned j) {
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		unsigned i_id, j_id;

		i_id = find(i);
		j_id = find(j);
		if (i_id == j_id)
			return;
		if (_rank[i_id] > _rank[j_id]) {
			_parent[j_id] = i_id;
			_tables[i_id] += _tables[j_id];
			_tables[j_id] = 0;
		}
		else {
			_parent[i_id] = j_id;
		if (_rank[i_id] == _rank[j_id])
			_rank[j_id] += 1;
		_tables[j_id] += _tables[i_id];
		_tables[i_id] = 0;
		}
		unsigned max = std::max(_tables[j_id], _tables[i_id]);
		_maxSize = std::max(max, _maxSize);
	}

	unsigned		maxSize() { return _maxSize; }

	void	print() {
		for (int i = 1; i < _tables.size(); ++i) {
			std::cout << "tables [" << _tables[i] << "]\tparent [" 
			<< _parent[i] << "]\trank [" << _rank[i] << "]"<< std::endl;
		}
		std::cout << "----------------------------" << std::endl;
	}
private:
	void	makeSet(unsigned i) {
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		_parent[i] = i;
		_rank[i] = 0;
	}

	unsigned		find(unsigned i) {
		//std::cout << __PRETTY_FUNCTION__ << std::endl;
		while (i != _parent[i])
			i = _parent[i];
		return i;
	}
	unsigned			_maxSize;
	std::vector<unsigned> _tables;
	std::vector<unsigned> _parent;
	std::vector<unsigned> _rank;
};

int		main(void) {

	int numTables, numRequests;

	std::cin >> numTables >> numRequests;

	Database database(numTables);
	//database.print();
	for (int i = 0; i < numRequests; ++i) {
		int dest, src;
		std::cin >> dest >> src;
		database.join(dest, src);
		//database.print();
		std::cout << database.maxSize() << std::endl;
	}	

	return 0;
}