#include <iostream>
#include <vector>
#include <algorithm>

struct Node
{
	int data;
	struct Node *parent;
	std::vector <struct Node*> ch;
};

int	Height(struct Node *root)
{
	int height = 1;

	for (auto c : root->ch)
		height = std::max(height, 1 + Height(c));
	return height;
}


struct Node *FindRoot(std::vector<int> &list)
{
	struct Node *root = new struct Node;
	root->parent = NULL;
	root->data = -1;
	for (int i = 0; i < list.size(); ++i)
	{
		if (list[i] == -1)
		{
			root->data = i;
			break;
		}
	}
	if (root->data < 0)
	{
		delete root;
		return NULL;
	}
	return root;
}

void	FindChildren(std::vector<int> &list, struct Node *root)
{
	for (int i = 0; i < list.size(); ++i)
	{
		if (list[i] == root->data)
		{
			struct Node *child = new struct Node;
			child->parent = root;
			child->data = i;
			FindChildren(list, child);
			root->ch.push_back(child);
		}
	}
}

struct Node *BuiltTree(std::vector<int> &tree)
{
	struct Node *root = FindRoot(tree);
	if (!root)
		return NULL;
	FindChildren(tree, root);
	return root;
}

void	PrintTree(struct Node *root)
{
	std::cout << root->data << std::endl;

	for (auto c : root->ch)
		PrintTree(c);
}

int	main(void)
{
	int n = 0;

	std::cin >> n ;
	if (n < 1)
		return 0;
	else if (n == 1)
	{
		std::cout << n << std::endl;
		return 0;
	}

	std::vector<int> v(n);

	for (int i = 0; i < v.size(); ++i)
		std::cin >> v[i];
	
	struct Node *root = BuiltTree(v);

	//PrintTree(root);
	if (root)
		std::cout << Height(root) << std::endl;
	else
		std::cout << 0 << std::endl;

	return 0;
}