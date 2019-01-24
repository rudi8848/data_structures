#include <iostream>
#include <vector>

/*
Найти количество компонент связности неориентированного графа при помощи поиска в глубину.

Формат входных данных:
На вход подаётся описание графа. В первой строке указаны два натуральных числа, разделенные
пробелом: число вершин v≤1000 и число рёбер e≤1000. В следующих e строках содержатся описания
рёбер. Каждое ребро задаётся разделённой пробелом парой номеров вершин, которые это ребро
соединяет. Считается, что вершины графа пронумерованы числами от 1 до v.

Формат выходных данных:

Одно число — количество компонент связности графа.

Sample Input 1:

4 2
1 2
3 2
Sample Output 1:

2
Sample Input 2:

4 3
1 2
3 2
4 3
Sample Output 2:

1
*/
void	dfs(int i, std::vector<bool> &v, int adj[][2], int max)
{

	v[i] = true;

	for (int j = 1; j < max; ++j)
	{
		if (adj[j][0] == adj[j][1] && adj[j][1] == i)
			return ;
		if (adj[j][0]  == i || adj[j][1] == i)
		{
			if (!v[adj[j][0]])
				dfs(adj[j][0], v, adj, max);
			else if (!v[adj[j][1]])
				dfs(adj[j][1], v, adj, max);
		}
	}
}

int		main(void)
{
	int v = 0;
	int e = 0;

	std::cin >> v >> e;
	if (v < 0 || e < 0)
		return 1;
    else if (v == 0 || e == 0)
    {
        std::cout << v << std::endl;
		return 0;
    }
	++v;
	++e;

	std::vector<bool> ver(v);
	
	for (bool i : ver)
		i = false;

	int adj[e][2];

	adj[0][0] = 0;
	adj[0][1] = 0;
	for  (int j = 1; j < e; ++j)
		std::cin >> adj[j][0] >> adj[j][1];

	int res = 0;
	int j = 1;
	while (j < ver.size())
	{
		if (j < ver.size() && ver[j])
		{
			while (j < ver.size() && ver[j])
				++j;
			++res;
		}
		else/*if (j < ver.size() && !ver[j])*/
		{
			dfs(j, ver, adj, e);
			while (j < ver.size() && ver[j])
				++j;
			++res;
		}
	}
	std::cout  << res << std::endl;
	return 0;
}