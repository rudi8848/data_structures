#include <iostream>
#include <vector>

int	main(void)
{
	int n = 0;
	int check = 0;
	std::cin >> n ;
	if (n < 1)
		return 0;

	std::vector<int> v(n);
	std::vector<int> depth(n);
	for (int i = 0; i < n; ++i)
		depth[i] = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		std::cin >> v[i];
		if (v[i] == -1)
			depth[i] = 1;
	}

	for (int i = 0; i < v.size(); ++i)
	{
		
		int parent = v[i];
		int height = 1;

		if (parent == -1)
			continue;
		if (depth[parent])
			height += depth[parent];
		else
		{
			while (!depth[parent])
			{
				++height;
				std::cout << ++check << std::endl;
				parent = v[parent];
			}
			height += depth[parent];
		}
		depth[i] = height;
	}

	int max = depth[0];
	for (int i = 0; i < depth.size(); ++i)
	{
		if (max < depth[i])
			max = depth[i];
	}
	std::cout <<max << std::endl;
	return 0;
}