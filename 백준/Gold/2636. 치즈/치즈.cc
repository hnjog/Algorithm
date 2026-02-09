#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

typedef pair<int, int> pii;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

int checks(vector<vector<int>>& maps, int sy, int sx)
{
	set<pii> rvs;
	
	queue<pii> q;
	q.push({ sy,sx });

	const int h = maps.size();
	const int w = maps[0].size();
	vector<vector<bool>> visited(h, vector<bool>(w, false));

	while (q.empty() == false)
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (visited[y][x])
			continue;

		visited[y][x] = true;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dirY[i];
			int nx = x + dirX[i];

			if (ny < 0 || ny >= h ||
				nx < 0 || nx >= w)
				continue;

			if (maps[ny][nx] == 1)
			{
				rvs.insert({ ny,nx });
				continue;
			}

			q.push({ ny, nx });
		}
	}


	for (auto& p : rvs)
	{
		maps[p.first][p.second] = 0;
	}

	return rvs.size();
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

	int lt = 0;
	int lc = 0;
	int plc = 0;

	while (true)
	{
		lc = checks(maps, 0, 0);

		if (lc == 0)
		{
			lc = plc;
			break;
		}
		else
		{
			lt++;
			plc = lc;
		}
	}

	cout << lt << '\n' << lc;

	return 0;
}