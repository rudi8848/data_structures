#include <iostream>
#include <vector>

class MinHeap
{
public:
	MinHeap(std::vector<int> &v) {
		_size = v.size();
		_heap = v;
		for (int i = _size / 2 + 1 ; i > -1 ; --i)
			SiftDown(i);
		_maxSize = _heap.capacity();
	}
	~MinHeap() {}

	int		Parent(int i) { return (i - 1) / 2; }
	int		LeftChild(int i) { return 2 * i + 1; }
	int		RightChild(int i) { return 2 * i + 2; }
	int		size() { return _size; }
	int 	maxSize() { return _maxSize; }
/*
	void	SiftUp(int i) {
		while (i > 0 && _heap[Parent(i)] > _heap[i])
		{
			_log.push_back(std::make_pair(_heap[Parent(i)], _heap[i]));
			std::swap(_heap[Parent(i)], _heap[i]);
			i = Parent(i);
		}
	}
*/
	void	SiftDown(int i) {
		int minIndex = i;
		int l = LeftChild(i);

		if (l < _size  && _heap[l] < _heap[minIndex])
			minIndex = l;

		int r = RightChild(i);
		if (r < _size  && _heap[r] < _heap[minIndex])
			minIndex = r;

		if (i != minIndex)
		{
			_log.push_back(std::make_pair(i, minIndex));
			std::swap(_heap[i], _heap[minIndex]);
			SiftDown(minIndex);
		}
	}
/*
	void	Insert(int p) {
		if (_size == _maxSize) {
			std::cout << "Max size!";
			return;
		}
		++_size;
		_heap[_size - 1] = p;
		SiftUp(_size - 1);
	}

	int 	ExtractMin() {
		int result = _heap[0];
		_heap[0] = _heap[_size - 1];
		--_size;
		SiftDown(0);
		return result;
	}

	void	Remove(int i) {
		_heap[i] = -1;
		SiftUp(i);
		ExtractMin();
	}

	void	ChangePriority(int i, int p) {
		int oldp = _heap[i];
		_heap[i] = p;
		if (p < oldp)
			SiftUp(i);
		else
			SiftDown(i);
	}
*/
	std::vector<int> const & heap() { return _heap; }
	std::vector<std::pair<int, int>> const & log() { return _log;}
	
private:
	std::vector<int>	_heap;

	int 				_size;
	int 				_maxSize;
std::vector<std::pair<int, int>> _log;
};


int	main(void)
{
	int n;

	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
		std::cin >> v[i];

	MinHeap heap(v);
	
	for (int i = 0; i < n; ++i)
		std::cout << heap.heap()[i] << " ";
	std::cout << std::endl;
	
	std::cout << heap.log().size() << std::endl;
	if (heap.log().size()) {
	for (int i = 0; i < heap.log().size(); ++i) {
		std::cout << heap.log()[i].first << " " << heap.log()[i].second << std::endl;
	}
}
	return 0;
}