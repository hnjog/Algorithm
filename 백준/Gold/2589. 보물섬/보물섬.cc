#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int h, w;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

inline bool checkRightArrange(int nowY, int nowX)
{
	if (nowY < 0 || nowY >= h ||
		nowX < 0 || nowX >= w)
		return false;

	return true;
}

struct edge
{
	int y, x, cost;
};

int find(vector<string>& maps, int nowY, int nowX)
{
	vector<vector<bool>> visit(h, vector<bool>(w, false));

	queue<edge> q;

	q.push({ nowY,nowX,0 });
	int ret = 0;

	visit[nowY][nowX] = true;

	while (q.empty() == false)
	{
		int ny = q.front().y;
		int nx = q.front().x;
		int ncost = q.front().cost;
		q.pop();

		if (ncost > ret)
		{
			ret = ncost;
		}

		for (int i = 0; i < 4; i++)
		{
			int nextY = ny + dirY[i];
			int nextX = nx + dirX[i];

			if (checkRightArrange(nextY, nextX) == false)
				continue;

			if (maps[nextY][nextX] == 'W')
				continue;

			if (visit[nextY][nextX])
				continue;

			visit[nextY][nextX] = true;
			q.push({ nextY,nextX,ncost + 1 });
		}
	}

	return ret;
}

int bfs(vector<string>& maps, int nowY, int nowX)
{
	if (checkRightArrange(nowY, nowX) == false)
		return 0;

	int ret = 0;

	if (maps[nowY][nowX] == 'W')
		return ret;

	vector<vector<bool>> check(h, vector<bool>(w, false));
	queue<edge> q;
	q.push({ nowY,nowX,0 });
	check[nowY][nowX] = true;

	vector<pair<int, int>> vValues;

	while (q.empty() == false)
	{
		int ny = q.front().y;
		int nx = q.front().x;
		int ncost = q.front().cost;
		q.pop();

		if (ncost >= ret)
		{
			if (ncost > ret)
			{
				ret = ncost;
				vValues.clear();
			}
			vValues.push_back({ ny,nx });
		}

		for (int i = 0; i < 4; i++)
		{
			int nextY = ny + dirY[i];
			int nextX = nx + dirX[i];

			if (checkRightArrange(nextY, nextX) == false)
				continue;

			if (maps[nextY][nextX] == 'W')
				continue;

			if (check[nextY][nextX])
				continue;

			check[nextY][nextX] = true;
			q.push({ nextY,nextX,ncost + 1 });
		}
	}

	ret = 0;

	for (auto& p : vValues)
	{
		int t = find(maps, p.first, p.second);
		if (t > ret)
			ret = t;
	}

	return ret;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> h >> w;

	vector<string> maps(h);
	for (int i = 0; i < h; i++)
		cin >> maps[i];

	int bestV = 0;

	vector<vector<bool>> visit(h, vector<bool>(w, false));

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (maps[i][j] == 'L')
			{
				int v = bfs(maps, i, j);
				if (v > bestV)
					bestV = v;
			}
		}
	}

	cout << bestV;

	return 0;
}