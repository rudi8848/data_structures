#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>

class Buf
{
public:
	Buf(int size): _size(size), _proc(0) {}
	~Buf() {}
	
	void				AddPackage(int time) {
		int duration = 0;
		std::cin >> duration;
		if (_check(time))
			_push(time, duration);
		else
			log.push_back(-1);
	}
	std::vector<int> log;

private:
	std::queue<int>		_buffer;
	int					_proc;
	int					_size;

	bool				_check(int time) {
		if (_buffer.empty())
			return true;
		if (_buffer.front() <= time)
			_buffer.pop();
		if (_buffer.size() < _size)
			return true;
		return false;
	}

	void				_push(int time, int duration) {
		time = std::max(time, _proc);
		log.push_back(time);
		_buffer.push(time + duration);
		_proc = std::max(time + duration, _proc);
	}
};

int		main(void)
{
	int size = 0;
	int n = 0;

	std::cin >> size >> n;

	if (n == 0)
		return 0;

	Buf buf(size);

	for (int i = 0; i < n; ++i) {
		int time = 0;
		std::cin >> time;
		buf.AddPackage(time);
	}

	for (auto i : buf.log)
		std::cout << i << std::endl;
	return 0;
}