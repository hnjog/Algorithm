#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0,-1 };

struct pos
{
	int y, x;
	int cost;
};

struct Compare
{
	bool operator()(const pos& a, const pos& b)
	{
		return a.cost > b.cost;
	}
};

int bfs(vector<vector<int>>& maps)
{
	int n = maps.size();

	priority_queue<pos, vector<pos>, Compare> pq;
	pq.push({ 0,0,0 });

	vector<vector<int>> visit(n, vector<int>(n, INT_MAX));

	while (pq.empty() == false)
	{
		int nowY = pq.top().y;
		int nowX = pq.top().x;
		int nowCost = pq.top().cost;
		pq.pop();

		if (nowY < 0 || nowY >= n ||
			nowX < 0 || nowX >= n)
			continue;

		// 현재 밟은 도둑 루피
		nowCost += maps[nowY][nowX];
		
		if (visit[nowY][nowX] <= nowCost)
			continue;
		
		visit[nowY][nowX] = nowCost;

		if (nowY == n - 1 && nowX == n - 1)
		{
			return nowCost;
		}

		for (int i = 0; i < 4; i++)
		{
			pq.push({ nowY + dirY[i],nowX + dirX[i],nowCost });
		}
	}

	return 0;
}

int main()
{
	int t = 0;
	while (true)
	{
		t++;
		int n;
		cin >> n;
		if (n == 0)
			break;

		vector<vector<int>> maps(n, vector<int>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> maps[i][j];

		cout << "Problem " << t << ": " << bfs(maps) << '\n';
	}

	return 0;
}