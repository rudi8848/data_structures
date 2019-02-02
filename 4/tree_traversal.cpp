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
	void	printInOrder(int v) {
		if (v == -1)
			return;
		printInOrder(_tree[v].left);
		std::cout << _tree[v].val << " ";
		printInOrder(_tree[v].right);
	}

	void	printPreOrder(int v) {
		if (v == -1)
			return;
		std::cout << _tree[v].val << " ";
		printPreOrder(_tree[v].left);
		printPreOrder(_tree[v].right);
	}

	void	printPostOrder(int v) {
		if (v == -1)
			return;
		printPostOrder(_tree[v].left);
		printPostOrder(_tree[v].right);
		std::cout << _tree[v].val << " ";
	}
private:
	std::vector<Node> _tree;
};

int			main(void) {
	int	n;
	std::cin >> n;
	Tree tree(n);
	tree.printInOrder(0);
	std::cout << std::endl;
	tree.printPreOrder(0);
	std::cout << std::endl;
	tree.printPostOrder(0);
	std::cout << std::endl;
	return 0;
}