#include <string>
#include <vector>
#include<queue>
#include<limits.h>

using namespace std;

struct node
{
	int x, y;
	int cost = 0;
};

struct Compare
{
	bool operator()(const node& a, const node& b)
	{
		return a.cost > b.cost;
	}
};

int BFS(int sx, int sy, int tx, int ty, vector<string>& maps)
{
	priority_queue<node, vector<node>, Compare> pq;
	vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
	vector<vector<int>> bp(maps.size(), vector<int>(maps[0].size(), INT_MAX));

	pq.push({ sx,sy,0 });
	bp[sy][sx] = 0;
	
	while (pq.empty() == false)
	{
		node no = pq.top();
		pq.pop();

		if (no.y < 0 || no.y >= maps.size() ||
			no.x < 0 || no.x >= maps[no.y].size())
			continue;

		if (visited[no.y][no.x] == true)
			continue;

		visited[no.y][no.x] = true;

		if (no.cost > bp[no.y][no.x])
			continue;

		bp[no.y][no.x] = no.cost;

		if (maps[no.y][no.x] == 'X')
			continue;

		if (no.x == tx &&
			no.y == ty)
		{
			return no.cost;
		}

		pq.push({ no.x + 1,no.y,no.cost + 1 });
		pq.push({ no.x - 1,no.y,no.cost + 1 });
		pq.push({ no.x,no.y + 1,no.cost + 1 });
		pq.push({ no.x,no.y - 1,no.cost + 1 });
	}

	return -1;
}

int solution(vector<string> maps) {
	int sx = 0, sy = 0, lx = 0, ly = 0, ex = 0, ey = 0;

	for (int y = 0; y < maps.size(); y++)
	{
		for (int x = 0; x < maps[y].size(); x++)
		{
			if (maps[y][x] == 'S')
			{
				sx = x;
				sy = y;
			}
			else if (maps[y][x] == 'L')
			{
				lx = x;
				ly = y;
			}
			else if (maps[y][x] == 'E')
			{
				ex = x;
				ey = y;
			}
		}
	}

	int lDis = BFS(sx, sy, lx, ly, maps);
	if (lDis == -1)
		return -1;

	int gDis = BFS(lx, ly, ex, ey, maps);
	if (gDis == -1)
		return -1;

	return lDis + gDis;
}