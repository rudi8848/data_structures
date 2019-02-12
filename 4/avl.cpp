#include <iostream>

#define x 1000000001
long long g_sum = 0;

long long f(long long val) {
	return (val % x  + g_sum % x) % x;
}


struct Node {
	long long key;
	unsigned char height;
	Node *left;
	Node *right;
	Node(int k) : key(k), height(1), left(NULL), right(NULL) {}
};

unsigned char	height(Node *p) {
	return p ? p->height : 0;
}

int				bfactor(Node *p) {
	return height(p->right) - height(p->left);
}

void			fixHeight(Node *p) {
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

Node*			rotateRight(Node *p) {
	Node *q = p->left;
	p->left = q->right;
	q->right = p;
	fixHeight(p);
	fixHeight(q);
	return q;
}

Node*			rotateLeft(Node *q) {
	Node *p = q->right;
	q->right = p->left;
	p->left = q;
	fixHeight(q);
	fixHeight(p);
	return p;
}

Node*			balance(Node *p) {
	fixHeight(p);
	if (bfactor(p) == 2) {
		if (bfactor(p->right) < 0)
			p->right = rotateRight(p->right);
		return rotateLeft(p);
	}
	if (bfactor(p) == -2) {
		if (bfactor(p->left) > 0)
			p->left = rotateLeft(p->left);
		return rotateRight(p);
	}
	return p;
}

Node*			insert(Node *p, long long k) {
	if (!p)
		return new Node(k);
	if (k < p->key)
		p->left = insert(p->left, k);
	else if (k > p->key)
		p->right = insert(p->right, k);
	return balance(p);
}

Node*			findMin(Node *p) {
	return p->left ? findMin(p->left) : p;
}

Node*			removeMin(Node* p) {
	if (!p->left)
		return p->right;
	p->left = removeMin(p->left);
	return balance(p);
}

Node*			remove(Node *p, long long k) {
	if (!p)
		return NULL;
	if (k < p->key)
		p->left = remove(p->left, k);
	else if (k > p->key)
		p->right = remove(p->right, k);
	else {
		Node *q = p->left;
		Node *r = p->right;
		delete p;
		p = NULL;
		if (!r)
			return q;
		Node *min = findMin(r);
		min->right = removeMin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

void			find(Node *node, long long k) {
	if (!node) {
		std::cout << "Not found" << std::endl;
		return ;
	}
	if (node->key == k) {
		std::cout << "Found" << std::endl;
		return ;
	}
	else if (k < node->key)
		find(node->left, k);
	else if (k > node->key)
		find(node->right, k);
}

void			inOrder(Node *v, long long const &left, long long const &right,long long &res) {
	if (!v)
		return;
	if (v->key > left)
		inOrder(v->left, left, right, res);
	if (v->key >= left && v->key <= right)
		res += v->key;
	if (v->key < right)
		inOrder(v->right, left, right, res);
}

long long		sum(Node *node, long long left, long long right) {
	long long sum = 0;
	inOrder(node, left, right, sum);
	g_sum = sum;
	return sum;
}

void			preOrder(Node *v) {
	if (!v)
		return;
	std::cout << v->key << " ";
	preOrder(v->left);
	preOrder(v->right);
}

int				main()
{
	unsigned n;
	long long key;
	long long l, r;
	l = r = 0;
	Node *tree = NULL;
	std::cin >> n;

	std::string operation;
	for (unsigned i = 0; i < n; ++i) {
		std::cin >> operation;
		if (operation == "+") {
			std::cin >> key;
			tree = insert(tree, f(key));
		}
		else if (operation == "-") {
			std::cin >> key;
			tree = remove(tree, f(key));
		}
		else if (operation == "?") {
			std::cin >> key;
			find(tree, f(key));
		}
		else if (operation == "s") {
			
			std::cin >> l >> r;
			std::cout << sum(tree, f(l), f(r)) <<std::endl;
		}
		/*
		std::cout << "--------------------" << std::endl;
		preOrder(tree);
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl;
		*/
	}
    return 0;
}

