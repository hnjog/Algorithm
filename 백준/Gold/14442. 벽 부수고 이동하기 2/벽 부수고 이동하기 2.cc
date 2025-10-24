#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<limits.h>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

int n, m, k;

struct infos
{
	int y, x;
	int cost;
	int remainK;
};

int bfs(vector<string>& maps)
{
	vector<vector<vector<int>>> visited(n, vector<vector<int>>(m,vector<int>(k + 1,INT_MAX)));

	queue<infos> q;
	q.push({ 0,0,1,k });
	visited[0][0][k] = 1;

	while (q.empty() == false)
	{
		int nowy = q.front().y;
		int nowx = q.front().x;
		int nowcost = q.front().cost;
		int nowRk = q.front().remainK;
		q.pop();

		if (nowy == n - 1 &&
			nowx == m - 1)
		{
			return nowcost;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = nowy + dirY[i];
			int nx = nowx + dirX[i];
			int ncost = nowcost + 1;
			int nextRk = nowRk;
			
			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m)
				continue;

			if (maps[ny][nx] == '1')
			{
				if (nextRk == 0)
					continue;

				nextRk--;
			}

			if (visited[ny][nx][nextRk] <= ncost)
				continue;

			visited[ny][nx][nextRk] = ncost;
			q.push({ ny,nx,ncost,nextRk });
		}

	}

	return -1;
}

int main()
{
	cin >> n >> m >> k;

	vector<string> maps(n);
	for (int i = 0; i < n; i++)
		cin >> maps[i];

	cout << bfs(maps);

	return 0;
}