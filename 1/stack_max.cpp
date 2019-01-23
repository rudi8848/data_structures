#include <iostream>
#include <stack>
#include <vector>

struct MaxStack
{
	void	pushv(int val) {
		values.push(val);
		if (maxv.empty())
			maxv.push(val);
		else
			maxv.push(std::max(maxv.top(), val));
	}

	void	popv() {
		if (!values.empty() && !maxv.empty())
		{
			values.pop();
			maxv.pop();
		}
	}

	int		max() {
		if (!maxv.empty())
			return maxv.top();
		else
			return -1;
	}

private:
	std::stack<int> values;
	std::stack<int> maxv;
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