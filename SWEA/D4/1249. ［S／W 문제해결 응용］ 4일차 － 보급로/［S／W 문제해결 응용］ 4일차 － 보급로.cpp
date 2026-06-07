#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<limits.h>

using namespace std;

struct infos
{
	int y, x, cost;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		return a.cost > b.cost;
	}
};

int Bfs(const vector<vector<int>>& maps)
{
	int n = maps.size();

	const int dirY[4] = { 0,-1,0,1 };
	const int dirX[4] = { -1,0,1,0 };

	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ 0,0,0 });

	vector<vector<int>> visited(n, vector<int>(n, INT_MAX));

	while (pq.empty() == false)
	{
		int nowY = pq.top().y;
		int nowX = pq.top().x;
		int nowCost = pq.top().cost;
		pq.pop();

		if (nowY < 0 || nowY >= n ||
			nowX < 0 || nowX >= n)
			continue;

		if (visited[nowY][nowX] <= nowCost)
			continue;

		visited[nowY][nowX] = nowCost;

		if (nowY == n - 1 &&
			nowX == n - 1)
		{
			return nowCost;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = nowY + dirY[i];
			int nx = nowX + dirX[i];

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= n)
				continue;

			pq.push({ ny,nx,nowCost + maps[ny][nx] });
		}
	}

	return -1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		vector<vector<int>> maps(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;

			for (int j = 0; j < n; j++)
			{
				maps[i][j] = str[j] - '0';
			}
		}

		cout << '#' << test_case << ' ' << Bfs(maps) << '\n';
	}
	return 0;
}