#include <iostream>
#include <vector>

struct Node
{
	int val;
	int left;
	int right;
};

class Tree
{
public:
	Tree(int n) {
		_tree.resize(n);
		int val, left, right;
		for (int i = 0; i < n; ++i) {
			std::cin >> val >> left >> right;
			_tree[i].val = val;
			_tree[i].left = left;
			_tree[i].right = right;
		}
	}
	~Tree() {}
	void	InOrder(int v) {
		if (v == -1)
			return;
		InOrder(_tree[v].left);
		_output.push_back(_tree[v].val);
		InOrder(_tree[v].right);
	}
	bool	check() {
		InOrder(0);
		int prev = _output[0];
		for (int i = 1; i < _output.size(); ++i) {
			int current = _output[i];
			if (! (current > prev))
				return false;
			prev = current;
		}
		
		return true;
	}
private:
	std::vector<Node> _tree;
	std::vector<int> _output;
};

int			main(void) {
	int	n;
	std::string	res;
	std::cin >> n;
	if (!n)
	{
		std::cout <<"CORRECT"<< std::endl;
		return 0;
	}
	Tree tree(n);
	res = tree.check() ? "CORRECT" : "INCORRECT";
	std::cout << res << std::endl;
	return 0;
}