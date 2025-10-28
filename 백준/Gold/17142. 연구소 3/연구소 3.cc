#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

int n, m;

struct infos
{
	int y, x;
	int time;
};

struct Compare
{
	bool operator()(infos& a, infos& b)
	{
		return a.time > b.time;
	}
};

int mapCount(const vector<vector<int>>& maps, const vector<vector<int>>& visit)
{
	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (maps[i][j] == 0)
			{
				if(visit[i][j] == -1)
					return -1;

				if (ret < visit[i][j])
					ret = visit[i][j];
			}
		}
	}

	return ret;
}

int bfs(const vector<vector<int>>& maps, const vector<pair<int, int>>& vPoss, vector<pair<int, int>>& startP)
{
	vector<vector<int>> visit(n, vector<int>(n, -1));

	priority_queue<infos, vector<infos>, Compare> pq;

	for (auto& p : startP)
	{
		visit[p.first][p.second] = 0;
		pq.push({ p.first,p.second,0 });
	}

	int ans = 0;

	while (pq.empty() == false)
	{
		int nowY = pq.top().y;
		int nowX = pq.top().x;
		int nowTime = pq.top().time;
		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = nowY + dirY[i];
			int nx = nowX + dirX[i];
			int nCost = nowTime + 1;

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= n)
				continue;

			// 벽
			if (maps[ny][nx] == 1)
				continue;

			if (visit[ny][nx] > 0)
				continue;

			visit[ny][nx] = nCost;

			pq.push({ ny,nx,nCost });
		}
	}

	return mapCount(maps, visit);
}

int recur(vector<vector<int>>& maps, vector<pair<int, int>>& vPoss, int now, vector<pair<int, int>>& poss)
{
	if (poss.size() == m)
	{
		return bfs(maps, vPoss, poss);
	}

	int vSize = vPoss.size();

	if (now == vSize)
		return -1;

	int ret = INT_MAX;
	bool bAllFail = true;


	for (int i = now; i < vSize; i++)
	{
		poss.push_back(vPoss[i]);

		int r = recur(maps, vPoss, i + 1, poss);
		if (r != -1)
		{
			bAllFail = false;
			if (r < ret)
				ret = r;
		}

		poss.pop_back();
	}

	if (bAllFail)
		return -1;

	return ret;
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> maps(n, vector<int>(n, 0));
	vector<pair<int, int>> vPoss;
	vPoss.reserve(m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 2)
				vPoss.push_back({ i,j });

		}
	}

	vector<pair<int, int>> temp;

	cout << recur(maps, vPoss, 0, temp);

	return 0;
}