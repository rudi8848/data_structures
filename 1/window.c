#include <iostream>
#include <stack>
#include <vector>
#include <utility>

/*	std::pair(val, max)*/
struct MaxStack
{
	void	push(int val) {
		
		_st.empty() ? _st.push(std::make_pair(val, val))
		: _st.push(std::make_pair(val, std::max(val, _st.top().second)));
	}

	void	pop() {
		if (!_st.empty())
			_st.pop();
	}

	int		max() {
		if (!_st.empty())
			return _st.top().second;
		else
			return -1;
	}

	int		top() {
		if (!_st.empty())
			return _st.top().first;
		else
			return -1;
	}

	bool	empty() { return _st.empty(); }

	int 	size() { return _st.size(); }

private:
	std::stack <std::pair<int, int>>	_st;
};

struct MaxQueue
{
	void	push(int val) {	_left.push(val); }

	void	pop() {
		if (_right.empty())
		{
			int size = _left.size();
			for (int i = 0; i < size; ++i)
			{
				int tmp = _left.top();
				_left.pop();
				_right.push(tmp);
			}
		}
		_right.pop();
	}

	int		max() {
		if (_right.empty())
		{
			int size =  _left.size();
			for (int i = 0; i < size; ++i)
			{
				int tmp = _left.top();
				_left.pop();
				_right.push(tmp);
			}
		}
		return std::max(_right.max(), _left.max());
	}

	int 	size() {
		return _left.size() + _right.size();
	}

	private:
		MaxStack		_left;
		MaxStack		_right;
};

int		main(void)
{
	int n, win;

	std::cin >> n;

	std::vector<int> input(n);
	

	for (int i = 0; i < n; ++i)
		std::cin >> input[i];

	std::cin >> win;
	int outsize = n - win + 1;
	std::vector<int> output (outsize);

	MaxQueue q;
	int i = 0;
	int j = 0;

	while (i < win)
	{
		q.push(input[i]);
		++i;
	}
	output[j] = q.max();
	++j;

	while (i < n)
	{
		q.pop();
		q.push(input[i]);
		output[j] = q.max();
		++j;
		++i;
	}
	
	for (int i = 0; i < output.size(); ++i)
		std::cout << output[i] << " ";
	return 0;
}