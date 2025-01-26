#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct pos
{
	int y, x;
};

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0,-1 };

void bfs(vector<vector<int>>& maps, int& idx, int& count, pos p)
{
	int y = p.y;
	int x = p.x;

	if (maps[y][x] != 1)
		return;

	int n = maps.size();
	int m = maps[0].size();

	queue<pos> q;
	q.push(p);

	while (q.empty() == false)
	{
		pos tempP = q.front();
		q.pop();

		int nowY = tempP.y;
		int nowX = tempP.x;

		if (nowY < 0 || nowY >= n ||
			nowX < 0 || nowX >= m)
			continue;

		if (maps[nowY][nowX] != 1)
			continue;

		maps[nowY][nowX] = idx;

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dirY[i];
			int nextX = nowX + dirX[i];
			q.push({ nextY,nextX });
		}
	}

	idx++;
	count++;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n, k;
		cin >> m >> n >> k;

		int idx = 2;
		int count = 0;

		vector<vector<int>> maps(n, vector<int>(m, 0));
		for (int j = 0; j < k; j++)
		{
			int x, y;
			cin >> x >> y;
			maps[y][x] = 1;
		}

		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				bfs(maps, idx, count, { a,b });
			}
		}

		cout << count << '\n';
	}

}