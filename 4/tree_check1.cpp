#include <iostream>
#include <vector>

struct Node
{
	long long val;
	int left;
	int right;
};

class Tree
{
public:
	Tree(int n) {
		_tree.resize(n);
		int  left, right;
		long long val;
		for (int i = 0; i < n; ++i) {
			std::cin >> val >> left >> right;
			_tree[i].val = val;
			_tree[i].left = left;
			_tree[i].right = right;
		}
	}
	~Tree() {}


void	check() {
	long long full_lo, full_hi;
	if (get_and_check_tree_range(0, full_lo, full_hi))
		std::cout << "CORRECT" << std::endl;
	else
		std::cout << "INCORRECT" << std::endl;
}
private:
	bool get_and_check_tree_range(int v, long long &lo, long long &hi) {

		lo = hi = _tree[v].val;
		if (_tree[v].left != -1)
		{
			long long left_lo, left_hi;
			if (!get_and_check_tree_range(_tree[v].left, left_lo, left_hi))
				return false;
			if (! (left_lo <= left_hi))
				return false;
			if (left_hi >= _tree[v].val)
				return false;
			lo = left_lo;
		}
		if (_tree[v].right != -1)
		{
			long long right_lo, right_hi;
			if (!get_and_check_tree_range(_tree[v].right, right_lo, right_hi))
				return false;
			if ( !(right_lo <= right_hi))
				return false;
			if (right_lo < _tree[v].val)
				return false;
			hi = right_hi;
		}
		return true;
	}

	std::vector<Node> _tree;
};

int			main(void) {
	int	n;
	std::cin >> n;
	if (!n)
	{
		std::cout <<"CORRECT"<< std::endl;
		return 0;
	}
	Tree tree(n);
	tree.check();
	return 0;
}