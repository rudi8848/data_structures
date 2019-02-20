#include <iostream>
#include <vector>

template <class T>
class MinHeap
{
public:
	MinHeap(int processors) {
		int tasks;
		std::cin >> tasks;
		int i = 0;

		while (i < processors) {
			_heap.push_back(std::make_pair(0, i));
			++i;
		}
		_size = processors;
		BuildHeap();

		i = 0;
		while (i < tasks)
		{
			int task;
			std::cin >> task;
			ChangePriority(task);
			++i;
		}
	}
	~MinHeap() {}

	void	BuildHeap() {
		for (int i = _size / 2 + 1 ; i > -1 ; --i)
			SiftDown(i);
	}

	int		Parent(int i) { 
		if (!i)
			return 0;
		return (i - 1) / 2;
	}
	int		LeftChild(int i) { return 2 * i + 1; }
	int		RightChild(int i) { return 2 * i + 2; }
	int		size() { return _size; }

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
			std::swap(_heap[i], _heap[minIndex]);
			SiftDown(minIndex);
		}
	}

	void	ChangePriority(unsigned long time) {
		_log.push_back(std::make_pair(_heap[0].second, _heap[0].first));
		_heap[0].first += time;
		SiftDown(0);
	}
	std::vector<T> const & heap() { return _heap; }
	std::vector<std::pair<int, unsigned long>> const & log() { return _log;}
	
private:
	std::vector<T>								_heap;
	std::vector<std::pair<int, unsigned long>> 	_log;
	int 										_size;
};

int main(void)
{
	int processors;

	std::cin >> processors ;
	MinHeap<std::pair<unsigned long, int>> heap(processors);
	for (int i = 0; i < heap.log().size(); ++i)
		std::cout << heap.log()[i].first << " " << heap.log()[i].second << std::endl;
	return 0;
}