#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

typedef pair<int, int> pii;

bool Bfs(vector<vector<int>>& maps)
{
	int h = maps.size();
	int w = maps[0].size();

	vector<vector<bool>> visit(h, vector<bool>(w, false));
	vector<vector<int>> counter(h, vector<int>(w, 0));

	set<pii> rs;
	queue<pii> q;
	q.push({ 0,0 });

	while (q.empty() == false)
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (visit[y][x])
			continue;

		visit[y][x] = true;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || ny >= h ||
				nx < 0 || nx >= w)
				continue;

			if (maps[ny][nx] == 1)
			{
				counter[ny][nx]++;
				if(counter[ny][nx] >= 2)
					rs.insert({ ny,nx });
				continue;
			}

			q.push({ ny,nx });
		}
	}

	bool checker = false;

	if (rs.size() > 0)
	{
		checker = true;
		for (auto& p : rs)
		{
			maps[p.first][p.second] = 0;
		}
	}

	return checker;
}

int main()
{
	int h, w;
	cin >> h >> w;

	vector<vector<int>> maps(h, vector<int>(w));

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> maps[i][j];
		}
	}

	int count = 0;

	while (true)
	{
		if (Bfs(maps) == false)
			break;

		count++;
	}

	cout << count;

	return 0;
}