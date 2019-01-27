#include <iostream>
#include <vector>
#include <climits>

class MaxHeap
{
public:
	MaxHeap(std::vector<int> &v) {
		_size = v.size();
		_heap = v;
		for (int i = _size / 2 +1 ; i > -1 ; --i)
			SiftDown(i);
		_maxSize = _heap.capacity();
	}
	~MaxHeap() {}

	int		Parent(int i) { return (i - 1) / 2; }
	int		LeftChild(int i) { return 2 * i + 1; }
	int		RightChild(int i) { return 2 * i + 2; }
	int		size() { return _size; }
	int 	maxSize() { return _maxSize; }

	void	SiftUp(int i) {
		while (i > 0 && _heap[Parent(i)] < _heap[i])
		{
			std::swap(_heap[Parent(i)], _heap[i]);
			i = Parent(i);
		}
	}

	void	SiftDown(int i) {
		int maxIndex = i;
		int l = LeftChild(i);

		if (l < _size && _heap[l] > _heap[maxIndex])
			maxIndex = l;

		int r = RightChild(i);
		if (r < _size  && _heap[r] > _heap[maxIndex])
			maxIndex = r;

		if (i != maxIndex)
		{
			std::swap(_heap[i], _heap[maxIndex]);
			SiftDown(maxIndex);
		}
	}

	void	Insert(int p) {
		if (_size == _maxSize) {
			std::cout << "Max size!";
			return;
		}
		++_size;
		_heap[_size - 1] = p;
		SiftUp(_size -1);
	}

	int 	ExtractMax() {
		int result = _heap[0];
		_heap[0] = _heap[_size -1];
		--_size;
		SiftDown(0);
		return result;
	}

	void	Remove(int i) {
		_heap[i] = INT_MAX;
		SiftUp(i);
		ExtractMax();
	}

	void	ChangePriority(int i, int p) {
		int oldp = _heap[i];
		_heap[i] = p;
		if (p > oldp)
			SiftUp(i);
		else
			SiftDown(i);
	}

	std::vector<int> const & heap() { return _heap; }

private:
	std::vector<int>	_heap;
	int 				_size;
	int 				_maxSize;

};


int main(void) {

	std::vector<int> v = {7, 11, 29, 12, 42, 18, 13, 18, 14};
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	MaxHeap h(v);

	for (int i = 0; i < h.size(); ++i)
		std::cout << h.heap()[i] << " ";
	std::cout << std::endl;


	std::cout << "\t\t\t" <<h.heap()[0] << std::endl;
	std::cout << "\t\t" << h.heap()[h.LeftChild(0)] << "\t\t" << h.heap()[h.RightChild(0)] << std::endl;
	std::cout << "\t"<< h.heap()[h.LeftChild(h.LeftChild(0))] << "\t" << h.heap()[h.RightChild(h.LeftChild(0))] << "\t\t" <<
	h.heap()[h.LeftChild(h.RightChild(0))] << "\t" << h.heap()[h.RightChild(h.RightChild(0))] << std::endl;
	std::cout << h.heap()[h.LeftChild(h.LeftChild(h.LeftChild(0)))] << "\t" <<  h.heap()[h.RightChild(h.LeftChild(h.LeftChild(0)))] << std::endl<< std::endl;

	h.ExtractMax();

for (int i = 0; i < h.size(); ++i)
		std::cout << h.heap()[i] << " ";
	std::cout << std::endl;
	std::cout << "\t\t\t" <<h.heap()[0] << std::endl;
	std::cout << "\t\t" << h.heap()[h.LeftChild(0)] << "\t\t" << h.heap()[h.RightChild(0)] << std::endl;
	std::cout << "\t"<< h.heap()[h.LeftChild(h.LeftChild(0))] << "\t" << h.heap()[h.RightChild(h.LeftChild(0))] << "\t\t" <<
	h.heap()[h.LeftChild(h.RightChild(0))] << "\t" << h.heap()[h.RightChild(h.RightChild(0))] << std::endl;
	std::cout << h.heap()[h.LeftChild(h.LeftChild(h.LeftChild(0)))]  << std::endl<< std::endl;


	h.Insert(58);

	for (int i = 0; i < h.size(); ++i)
		std::cout << h.heap()[i] << " ";
	std::cout << std::endl;

	std::cout << "\t\t\t" <<h.heap()[0] << std::endl;
	std::cout << "\t\t" << h.heap()[h.LeftChild(0)] << "\t\t" << h.heap()[h.RightChild(0)] << std::endl;
	std::cout << "\t"<< h.heap()[h.LeftChild(h.LeftChild(0))] << "\t" << h.heap()[h.RightChild(h.LeftChild(0))] << "\t\t" <<
	h.heap()[h.LeftChild(h.RightChild(0))] << "\t" << h.heap()[h.RightChild(h.RightChild(0))] << std::endl;
	std::cout << h.heap()[h.LeftChild(h.LeftChild(h.LeftChild(0)))] << "\t" <<  h.heap()[h.RightChild(h.LeftChild(h.LeftChild(0)))] << std::endl<< std::endl;

	return 0;
}
