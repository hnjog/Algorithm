#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

struct infos
{
	int y, x;
	int cost;
};

int n, m, t;

int bfs(vector<vector<int>>& maps, int targetY,int targetX, bool bFindSword)
{
	queue<infos> q;
	q.push({ 0,0,0 });

	vector<vector<int>> visit(n, vector<int>(m, INT_MAX));
	visit[0][0] = 0;

	while (q.empty() == false)
	{
		int nowY = q.front().y;
		int nowX = q.front().x;
		int nowCost = q.front().cost;
		q.pop();

		if (nowY == targetY &&
			nowX == targetX)
		{
			if (bFindSword)
			{
				int f = (n - 1 - targetY) + (m - 1 - targetX);
				return nowCost + f;
			}

			return nowCost;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = dirY[i] + nowY;
			int nx = dirX[i] + nowX;
			int ncost = nowCost + 1;

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m)
				continue;

			if (maps[ny][nx] == 1)
				continue;

			if (ncost > t)
				continue;

			if (visit[ny][nx] <= ncost)
				continue;

			visit[ny][nx] = ncost;
			q.push({ ny,nx,ncost });
		}
	}

	return INT_MAX;
}

int main()
{
	cin >> n >> m >> t;
	vector<vector<int>> maps(n, vector<int>(m, 0));

	pair<int, int> sPos;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 2)
				sPos = { i,j };
		}
	}

	int b = bfs(maps, n - 1, m - 1, false);
	int b2 = bfs(maps, sPos.first, sPos.second, true);

	if (b > b2)
		b = b2;

	if (b <= t)
		cout << b;
	else
		cout << "Fail";

	return 0;
}