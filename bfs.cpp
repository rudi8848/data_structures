#include <iostream>
#include <vector>
#include <queue>

/*
На вход программе подаётся описание простого связного графа. Первая строка содержит два числа:
число вершин V≤10000 и число рёбер E≤30000 графа. Следующие E строк содержат номера пар вершин,
соединенных рёбрами. Вершины имеют номера от 0 до V−1. Выведите список из V чисел — расстояний
от вершины 0 до соответствующих вершин графа.

Sample Input:

6 7
0 1
1 2
2 0
3 2
4 3
4 2
5 4
Sample Output:

0 1 1 2 2 3
*/
void	bfs(std::vector<std::vector<int>> &list, int v, int e)
{
	std::vector<bool> marked(v);
	std::vector<int> distance(v);
	std::vector<int> path(v);
	std::queue<int> q;
	int cur = 0;

	for (auto i : marked)
		i = false;
	for (auto i : distance)
		i = 0;
	q.push(cur);
	marked[cur] = true;
	distance[cur] = 0;
	path[cur] = -1;
	
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		for ( int j = 0; j < list.size(); ++j)
		{
			int point = -1;
			if (list[j][0] == cur)
				point = list[j][1];
			else if (list[j][1] == cur)
				point = list[j][0];
			
			if (point >= 0 && !marked[point])
			{
				q.push(point);
				distance[point] = distance[cur] + 1;
				marked[point] = true;
				path[point] = cur;
			}
		}
	}
	for (int i : distance)
		std::cout << i << std::endl;
	/*
//find path to 4
	int f = 4;
	if(!marked[f])
		std::cout << "No path" << std::endl;
	else
	{
		std::vector <int> way;
		for (int p = f; p != -1; p = path[p])
			way.push_back(p);
		std::cout << "Path to " << f << std::endl;
		for (int k : way)
			std::cout << k << std::endl;
	}
	*/
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
    std::vector < std::vector<int> > g;
    for  (int j = 0; j < e; ++j)
    {
    	int a, b;
		std::cin >> a >> b;
		g.push_back(std::vector<int>({a, b}));
    }
	bfs(g, v, e);
    return 0;
}
