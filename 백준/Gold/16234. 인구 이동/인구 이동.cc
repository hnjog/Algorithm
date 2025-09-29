#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, l, r;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

bool bfs(vector<vector<int>>& maps, vector<vector<bool>>& visit, int y, int x)
{
	if (visit[y][x])
		return false;

	long sumValue = 0;
	vector<pair<int, int>> vecs;
	queue<pair<int, int>> q;

	q.push({ y,x });

	visit[y][x] = true;

	while (q.empty() == false)
	{
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		vecs.push_back({ nowY,nowX });
		sumValue += maps[nowY][nowX];

		for (int i = 0; i < 4; i++)
		{
			int ny = nowY + dirY[i];
			int nx = nowX + dirX[i];

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= n)
				continue;

			if (visit[ny][nx])
				continue;

			int mV = abs(maps[nowY][nowX] - maps[ny][nx]);

			if (mV < l || mV > r)
				continue;

			visit[ny][nx] = true;
			q.push({ ny,nx });
		}
	}

	if (vecs.size() <= 1)
		return false;

	int v = sumValue / vecs.size();
	for (auto& p : vecs)
	{
		maps[p.first][p.second] = v;
	}

	return true;
}

int main()
{
	cin >> n >> l >> r;
	vector<vector<int>> maps(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> maps[i][j];

	int answer = 0;

	while (true)
	{
		bool dayNotChanged = true;

		vector<vector<bool>> visit(n, vector<bool>(n, false));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visit[i][j] == false)
				{
					if (bfs(maps, visit, i, j))
					{
						dayNotChanged = false;
					}
				}
			}
		}
		if (dayNotChanged)
			break;

		answer++;
	}

	cout << answer;

	return 0;
}