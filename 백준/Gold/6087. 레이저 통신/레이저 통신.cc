#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

struct infos
{
	int  y, x;
	int useCount;
	int dir;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		return a.useCount > b.useCount;
	}
};

int findV(vector<vector<char>>& maps, pair<int, int>& start, pair<int, int>& end)
{
	int h = maps.size();
	int w = maps[0].size();

	vector<vector<vector<int>>> dps(h, vector<vector<int>>(w, vector<int>(4, 1e9)));

	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ start.first,start.second,0,0 });
	pq.push({ start.first,start.second,0,1 });
	pq.push({ start.first,start.second,0,2 });
	pq.push({ start.first,start.second,0,3 });

	while (pq.empty() == false)
	{
		int nowy = pq.top().y;
		int nowx = pq.top().x;
		int nowcount = pq.top().useCount;
		int nowdir = pq.top().dir;
		pq.pop();

		if (dps[nowy][nowx][nowdir] <= nowcount)
			continue;

		dps[nowy][nowx][nowdir] = nowcount;

		if (end.first == nowy &&
			end.second == nowx)
			return nowcount;

		for (int i = 0; i < 4; i++)
		{
			int nexty = nowy + dirY[i];
			int nextx = nowx + dirX[i];
			int ncount = nowcount + 1;
			if (nowdir == i)
				ncount--;

			if (nexty < 0 || nexty >= h ||
				nextx < 0 || nextx >= w)
				continue;

			if (maps[nexty][nextx] == '*')
				continue;

			pq.push({ nexty,nextx,ncount,i });
		}
	}


	return -1;
}

int main()
{
	int w, h;
	cin >> w >> h;

	vector<vector<char>> maps(h, vector<char>(w));

	bool bInits = false;
	pair<int, int> start, end;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> maps[i][j];

			if (maps[i][j] == 'C')
			{
				if (bInits == false)
				{
					start.first = i;
					start.second = j;
					bInits = true;
				}
				else
				{
					end.first = i;
					end.second = j;
				}
			}
		}
	}

	cout << findV(maps, start, end);

	return 0;
}