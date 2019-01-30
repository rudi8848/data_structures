#include <iostream>
#include <vector>

class DisjoinSet
{
public:
	DisjoinSet(unsigned numVariables) {
		_rank.resize(numVariables + 1);
		_parent.resize(numVariables + 1);
		for (int i = 1; i < numVariables + 1; ++i)
			makeSet(i);

	}
	~DisjoinSet() {}

	void	join(unsigned i, unsigned j) {

		unsigned i_id, j_id;

		i_id = find(i);
		j_id = find(j);
		if (i_id == j_id)
			return;
		if (_rank[i_id] > _rank[j_id])
			_parent[j_id] = i_id;
		else
			_parent[i_id] = j_id;

		if (_rank[i_id] == _rank[j_id])
			_rank[j_id] += 1;
	}

	unsigned		find(unsigned i) {
		while (i != _parent[i])
			i = _parent[i];
		return i;
	}
private:
	void	makeSet(unsigned i) {
		_parent[i] = i;
		_rank[i] = 0;
	}

	std::vector<unsigned> 	_parent;
	std::vector<unsigned> 	_rank;
};

int		main(void)
{
	unsigned numVariables, equal, notEqual;

	std::cin >> numVariables >> equal >> notEqual;

	if (!notEqual) {
		std::cout << "1" << std::endl;
		return 0;
	}

	DisjoinSet set(numVariables);
	unsigned a, b;

	for (int i = 0; i < equal; ++i){	
		std::cin >> a >> b;
		set.join(a, b);
	}
	for (int i = 0; i < notEqual; ++i) {
		std::cin >> a >> b;
		if (set.find(a) == set.find(b)) {
			std::cout << "0" << std::endl;
			return 0;
		}
	}
	std::cout << "1" << std::endl;
	return 0;
}