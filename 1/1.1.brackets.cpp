#include <iostream>
#include <string>
#include <stack>
#include <iterator>

struct iset
{
	int index;
	char ch;
};

int		check_brackets(std::string const & str)
{
	std::stack<struct iset> stack;
	
	auto i = str.begin();
	for (struct iset c; i < str.end(); ++i)
	{
		c.ch = *i;
		c.index = i+1 - str.begin();
		if (c.ch == '{' || c.ch == '(' || c.ch == '[')
			stack.push(c);
		else if (c.ch == '}' || c.ch == ')' || c.ch == ']')
		{
			if (stack.empty())
				return ++i - str.begin();
			if (c.ch == '}' && stack.top().ch != '{')
				return ++i - str.begin();
			else if (c.ch == ')' && stack.top().ch != '(')
				return ++i - str.begin();
			else if (c.ch == ']' && stack.top().ch != '[')
				return ++i - str.begin();
			else
				stack.pop();
		}
	}
	if (!stack.empty())
		return stack.top().index;
	return -1;
}

int		main(void)
{
	std::string str;
	std::cin >> str;
	int ret = 0;
	if ((ret = check_brackets(str)) >= 0)
		std::cout << ret << std::endl;
	else
		std::cout << "Success" << std::endl;
	return 0;
}