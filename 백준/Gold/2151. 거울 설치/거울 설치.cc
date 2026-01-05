#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

struct Infos
{
	int y, x;
	int cost;
	int dir;
};

struct Compare
{
	bool operator()(const Infos& a,const Infos& b)
	{
		return a.cost > b.cost;
	}
};

int sy, sx, ty, tx;

int GetVal(vector<string>& maps)
{
	int n = maps.size();
	priority_queue<Infos, vector<Infos>, Compare> pq;

	// n x n 4방향
	vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(n, vector<bool>(4, false)));

	pq.push({ sy,sx,0,0 });
	pq.push({ sy,sx,0,1 });
	pq.push({ sy,sx,0,2 });
	pq.push({ sy,sx,0,3 });

	while (pq.empty() == false)
	{
		int nowy = pq.top().y;
		int nowx = pq.top().x;
		int nowc = pq.top().cost;
		int nowd = pq.top().dir;
		pq.pop();

		if (nowy < 0 || nowy >= n ||
			nowx < 0 || nowx >= n)
			continue;

		if (maps[nowy][nowx] == '*')
			continue;

		if (visited[nowy][nowx][nowd])
			continue;

		visited[nowy][nowx][nowd] = true;

		if (nowy == ty && nowx == tx)
			return nowc;

		if (maps[nowy][nowx] == '!')
		{
			int d1 = (nowd - 1) < 0 ? 3 : nowd - 1;
			int d2 = (nowd + 1) > 3 ? 0 : nowd + 1;

			pq.push({ nowy + dirY[d1],nowx + dirX[d1],nowc + 1,d1 });
			pq.push({ nowy + dirY[d2],nowx + dirX[d2],nowc + 1,d2 });
			pq.push({ nowy + dirY[nowd],nowx + dirX[nowd],nowc,nowd });
		}
		else
		{
			pq.push({ nowy + dirY[nowd],nowx + dirX[nowd],nowc,nowd});
		}
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;
	vector<string> maps(n);

	bool bInit = false;

	for (int i = 0; i < n; i++)
	{
		cin >> maps[i];

		for (int j = 0; j < n; j++)
		{
			if (maps[i][j] == '#')
			{
				if (bInit == false)
				{
					sy = i;
					sx = j;
					bInit = true;
				}
				else
				{
					ty = i;
					tx = j;
				}
			}
		}
	}

	cout << GetVal(maps);

	return 0;
}