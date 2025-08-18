#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int startY, startX;

struct infos
{
	int y, x;
	int cost;
};

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0,-1 };

void func(const vector<vector<int>>& maps)
{
	int n = maps.size();
	int m = maps[0].size();
	vector<vector<int>> result(n,vector<int>(m,INT_MAX));
	vector<vector<bool>> visited(n,vector<bool>(m,false));

	queue<infos> q;
	q.push({ startY,startX,0 });

	while (q.empty() == false)
	{
		int nowY = q.front().y;
		int nowX = q.front().x;
		int nowCost = q.front().cost;
		q.pop();

		if (nowY < 0 || nowY >= n ||
			nowX < 0 || nowX >= m)
			continue;

		if (maps[nowY][nowX] == 0)
		{
			continue;
		}

		if (result[nowY][nowX] <= nowCost)
			continue;

		result[nowY][nowX] = nowCost;
		visited[nowY][nowX] = true;

		for (int i = 0; i < 4; i++)
		{
			int ny = nowY + dirY[i];
			int nx = nowX + dirX[i];

			q.push({ ny,nx,nowCost + 1 });
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j] == 1 && visited[i][j] == false)
				cout << -1 << ' ';
			else if (result[i][j] == INT_MAX)
				cout << 0 << ' ';
			else
				cout << result[i][j] << ' ';
		}

		cout << '\n';
	}

}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> vec[i][j];
			if (vec[i][j] == 2)
			{
				startY = i;
				startX = j;
			}
		}
	}

	func(vec);
}