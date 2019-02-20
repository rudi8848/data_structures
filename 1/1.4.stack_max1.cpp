#include <iostream>
#include <stack>
#include <vector>
#include <utility>

/*	std::pair(val, max)*/
struct MaxStack
{
	void	pushv(int val) {
		_st.empty() ? _st.push(std::make_pair(val, val))
		: _st.push(std::make_pair(val, std::max(val, _st.top().second)));
	}

	void	popv() {
		if (!_st.empty())
			_st.pop();
	}

	int		max() {
		if (!_st.empty())
			return _st.top().second;
		else
			return -1;
	}

private:
	std::stack <std::pair<int, int>>	_st;
};

void	read_commands(int n)
{
	std::string command;
	int val;
	MaxStack st;
	int ret;

	std::vector<int> log;
	while (n != 0)
	{
		std::cin >> command;
		if (command == "max")
		{
			ret = st.max();
			if (ret >= 0)
				log.push_back(ret);
		}
		else if (command == "pop")
				st.popv();
		else if (command == "push")
		{
			std::cin >> val;
				st.pushv(val);
		}
		--n;
	}
	for (int i = 0; i < log.size(); ++i)
		std::cout << log[i] << std::endl;
}

int		main(void)
{
	int n = 0;
	std::cin >> n;

	if (n)
		read_commands(n);
	return 0;
}