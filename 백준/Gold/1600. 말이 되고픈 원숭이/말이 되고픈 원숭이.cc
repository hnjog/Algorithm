#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int k;
int w, h;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

const int hY[8] = { 2,2,1,1,-1,-1,-2,-2 };
const int hX[8] = { 1,-1,2,-2,2,-2,1,-1 };

struct infos
{
	int y, x;
	int cost;
	int useK;
};

inline bool checkRange(int y, int x)
{
	if (y < 0 || y >= h ||
		x < 0 || x >= w)
		return false;

	return true;
}

inline bool checkCan(const vector<vector<int>>& maps, vector<vector<vector<int>>>& visit, infos& n)
{
	if (checkRange(n.y, n.x) == false)
		return false;

	if (maps[n.y][n.x] == 1)
		return false;

	if (visit[n.useK][n.y][n.x] <= n.cost)
		return false;

	return true;
}

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		if (a.cost == b.cost)
			return a.useK > b.useK;

		return a.cost > b.cost;
	}
};

int bfs(vector<vector<int>>& maps)
{
	vector<vector<vector<int>>> visit(k + 1, vector<vector<int>>(h, vector<int>(w, 5000000)));

	priority_queue<infos, vector<infos>, Compare> q;
	q.push({ 0,0,0,0 });

	while (q.empty() == false)
	{
		infos i = q.top();
		q.pop();

		if (checkCan(maps, visit, i) == false)
			continue;

		visit[i.useK][i.y][i.x] = i.cost;

		if (i.y == h - 1 &&
			i.x == w - 1)
		{
			return i.cost;
		}

		for (int j = 0; j < 4; j++)
		{
			q.push({ i.y + dirY[j],i.x + dirX[j],i.cost + 1,i.useK });
		}

		if (i.useK < k)
		{
			for (int j = 0; j < 8; j++)
			{
				q.push({ i.y + hY[j],i.x + hX[j],i.cost + 1,i.useK + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	cin >> k;
	cin >> w >> h;
	vector<vector<int>> maps(h, vector<int>(w, -1));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> maps[i][j];
		}
	}

	cout << bfs(maps);

	return 0;
}