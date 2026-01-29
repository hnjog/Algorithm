#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int maps[501][501] = { 0, };

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2)
			swap(x1, x2);

		if (y1 > y2)
			swap(y1, y2);

		for (int y = y1; y <= y2; y++)
		{
			for (int x = x1; x <= x2; x++)
			{
				maps[y][x] = 1;
			}
		}
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2)
			swap(x1, x2);

		if (y1 > y2)
			swap(y1, y2);

		for (int y = y1; y <= y2; y++)
		{
			for (int x = x1; x <= x2; x++)
			{
				maps[y][x] = -1;
			}
		}
	}

	vector<vector<int>> visited(501, vector<int>(501, 1e9));

	struct infos
	{
		int y, x;
		int cost;
	};

	struct Compare
	{
		bool operator()(infos& a, infos& b)
		{
			return a.cost > b.cost;
		}
	};

	priority_queue<infos,vector<infos>,Compare> pq;
	pq.push({ 0,0,0 });
	visited[0][0] = 0;

	while (pq.empty() == false)
	{
		int nowy = pq.top().y;
		int nowx = pq.top().x;
		int nowcost = pq.top().cost;
		pq.pop();

		if (nowy == 500 &&
			nowx == 500)
		{
			cout << nowcost;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = nowy + dirY[i];
			int nx = nowx + dirX[i];
			int nc = nowcost;

			if (ny < 0 || ny > 500 ||
				nx < 0 || nx > 500)
				continue;

			if (maps[ny][nx] == -1)
				continue;

			if (maps[ny][nx] == 1)
				nc++;

			if (visited[ny][nx] <= nc)
				continue;

			visited[ny][nx] = nc;

			pq.push({ ny,nx,nc });
		}
	}

	cout << -1;

	return 0;
}