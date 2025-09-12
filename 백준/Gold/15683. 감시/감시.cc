#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

struct pos
{
	int y, x;
};

int n, m;

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0, 1,0,-1 };

void sprayView(vector<vector<int>>& map, const pos& p, int mainDir,vector<pos>& ret)
{
	int y = p.y;
	int x = p.x;

	int ny = y, nx = x;

	while (true)
	{
		ny += dirY[mainDir];
		nx += dirX[mainDir];

		if (ny < 0 || ny >= n ||
			nx < 0 || nx >= m)
			break;

		if (map[ny][nx] <= 0)
		{
			map[ny][nx]--;
			ret.push_back({ ny,nx });
		}

		if (map[ny][nx] == 6)
			break;
	}
}

vector<pos> setView(vector<vector<int>>& map, const pos& p, int mainDir)
{
	vector<pos> ret;

	switch (map[p.y][p.x])
	{
	case 1:
	{
		sprayView(map, p, mainDir, ret);
	}
	break;
	case 2:
	{
		sprayView(map, p, mainDir, ret);
		int subDir = (mainDir + 2) % 4;
		sprayView(map, p, subDir, ret);
	}
	break;
	case 3:
	{
		sprayView(map, p, mainDir, ret);
		int subDir = mainDir - 1;
		if (subDir < 0)
			subDir = 3;
		sprayView(map, p, subDir, ret);
	}
	break;
	case 4:
	{
		sprayView(map, p, mainDir, ret);
		int subDir = mainDir - 1;
		if (subDir < 0)
			subDir = 3;
		sprayView(map, p, subDir, ret);

		int subDir2 = mainDir + 1;
		if (subDir2 > 3)
			subDir2 = 0;
		sprayView(map, p, subDir2, ret);
	}
	break;
	case 5:
	{
		sprayView(map, p, mainDir, ret);
		int subDir = mainDir - 1;
		if (subDir < 0)
			subDir = 3;
		sprayView(map, p, subDir, ret);

		int subDir2 = mainDir + 1;
		if (subDir2 > 3)
			subDir2 = 0;
		sprayView(map, p, subDir2, ret);

		int subDir3 = mainDir + 2;
		if (subDir3 > 3)
			subDir3 = 0;
		sprayView(map, p, subDir3, ret);
	}
	break;
	}

	return ret;
}

int recur(vector<vector<int>>& map, vector<pos>& cameraPoss, int idx)
{
	// -1 -2 처럼 보고 있는 시야를 중첩할 예정시킬 생각임
	int cSize = cameraPoss.size();
	if (idx == cSize)
	{
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 0)
					ret++;
			}
		}

		return ret;
	}

	int ret = INT_MAX;
	for (int i = 0; i < 4; i++)
	{
		vector<pos> poss = setView(map, cameraPoss[idx], i);
		ret = min(ret, recur(map, cameraPoss, idx + 1));
		if (ret == 0)
			return 0;

		for (auto& p : poss)
		{
			int y = p.y;
			int x = p.x;
			map[y][x]++;
		}

		if (map[cameraPoss[idx].y][cameraPoss[idx].x] == 2 &&
			i > 2)
			break;
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m, 0));
	vector<pos> cameraPoss, crossSet;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 6)
				continue;

			if (map[i][j] > 0)
			{
				if (map[i][j] == 5)
					crossSet.push_back({ i,j });
				else
					cameraPoss.push_back({ i,j });
			}
		}
	}

	for (auto& p : crossSet)
	{
		setView(map, p, 0);
	}

	cout << recur(map, cameraPoss, 0);


	return 0;
}