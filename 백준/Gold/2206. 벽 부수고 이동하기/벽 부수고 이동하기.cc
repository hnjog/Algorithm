#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<string.h>

using namespace std;

struct pos
{
	int y,x;
	int cost;
	bool useBreak;
};

struct Compare
{
	bool operator()(const pos& a, const pos& b)
	{
		if (a.cost == b.cost)
			return a.useBreak < b.useBreak;

		return a.cost > b.cost;
	}
};

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0 ,-1};

vector<vector<int>> maps;
int dp[1001][1001][2];

int bfs()
{
	fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), INT_MAX);
	priority_queue<pos, vector<pos>, Compare> pq;
	pq.push({ 0,0,1,false });

	int h = maps.size();
	int w = maps[0].size();

	while (pq.empty() == false)
	{
		pos p = pq.top();
		pq.pop();

		int nowY = p.y;
		int nowX = p.x;
		int nowCost = p.cost;
		
		if (nowY < 0 || nowY >= h ||
			nowX < 0 || nowX >= w)
			continue;

		if (nowCost >= dp[nowY][nowX][p.useBreak])
			continue;

		dp[nowY][nowX][p.useBreak] = nowCost;

		if (nowY == h - 1 &&
			nowX == w - 1)
		{
			return nowCost;
		}
		
		if (maps[nowY][nowX] == 1)
		{
			if (p.useBreak)
				continue;

			for (int i = 0; i < 4; i++)
			{
				int nextY = nowY + dirY[i];
				int nextX = nowX + dirX[i];

				pq.push({ nextY,nextX,nowCost + 1,true });
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int nextY = nowY + dirY[i];
				int nextX = nowX + dirX[i];

				pq.push({ nextY,nextX,nowCost + 1,p.useBreak});
			}
		}
	}

	return -1;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	maps = vector<vector<int>>(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		for (int j = 0; j < m; j++)
		{
			maps[i][j] = int(t[j] - '0');
		}
	}

	cout << bfs();
}