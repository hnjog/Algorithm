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
const int dirX[4] = { 0,1,0 ,-1 };

vector<vector<int>> maps;
vector<vector<bool>> visit;
vector<pos> starts;

int bfs(int needCount)
{
	if (needCount == 0)
		return 0;
	
	int ret = -1;
	int h = maps.size();
	int w = maps[0].size();
	
	queue<pos> rq;
	for (pos p : starts)
	{
		rq.push(p);
	}


	while (true)
	{
		queue<pos> wq;
		ret++;
		while (rq.empty() == false)
		{
			pos p = rq.front();
			rq.pop();

			int ny = p.y;
			int nx = p.x;

			if (ny < 0 || ny >= h ||
				nx < 0 || nx >= w)
				continue;

			if (maps[ny][nx] == -1)
				continue;

			if (visit[ny][nx] == true)
				continue;

			visit[ny][nx] = true;

			if(maps[ny][nx] == 0)
				needCount--;

			if (needCount == 0)
			{
				return ret;
			}

			for (int i = 0; i < 4; i++)
			{
				int nextY = ny + dirY[i];
				int nextX = nx + dirX[i];
				wq.push({ nextY,nextX });
			}
		}

		if (wq.empty())
			break;

		rq = wq;
	}

	return -1;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int h, w;
	cin >> w >> h;

	maps = vector<vector<int>>(h, vector<int>(w, -1));
	visit = vector<vector<bool>>(h, vector<bool>(w, false));

	int needCount = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int t;
			cin >> t;
			maps[i][j] = t;

			if (t == 1)
			{
				starts.push_back({ i,j });
			}
			else if (t == 0)
			{
				needCount++;
			}
		}
	}

	cout << bfs(needCount);

}