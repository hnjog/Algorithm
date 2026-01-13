#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

pii upPos, downPos;

// 상 우 하 좌
const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0,-1 };

// 공기청정기 바람 방향(역순)
const int upD[4] = { 0,1,2,3 };
const int doD[4] = { 2,1,0,3 };

void Dusting(vector<vector<int>>& maps)
{
	int r = maps.size();
	int c = maps[0].size();

	vector<vector<int>> checkMaps(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (maps[i][j] <= 0)
				continue;

			int v = maps[i][j] / 5;
			int n = maps[i][j];

			for (int k = 0; k < 4; k++)
			{
				int ny = i + dirY[k];
				int nx = j + dirX[k];

				if (ny < 0 || ny >= r ||
					nx < 0 || nx >= c)
					continue;

				if (maps[ny][nx] == -1)
					continue;

				checkMaps[ny][nx] += v;
				n -= v;
			}

			maps[i][j] = n;
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			maps[i][j] += checkMaps[i][j];
		}
	}
}

void Cleaning(vector<vector<int>>& maps)
{
	int r = maps.size();
	int c = maps[0].size();

	int upLimY = upPos.first;
	int doLimY = downPos.first;
	
	pii nowUpPos = upPos;
	pii nextUpPos = upPos;
	int upDir = 0;

	while (true)
	{
		nextUpPos.first = nowUpPos.first + dirY[upD[upDir]];
		nextUpPos.second = nowUpPos.second + dirX[upD[upDir]];

		if (nextUpPos.first < 0 || nextUpPos.first > upLimY ||
			nextUpPos.second < 0 || nextUpPos.second >= c)
		{
			upDir++;
			continue;
		}

		if (maps[nextUpPos.first][nextUpPos.second] == -1)
		{
			maps[nowUpPos.first][nowUpPos.second] = 0;
			break;
		}

		if (maps[nowUpPos.first][nowUpPos.second] != -1)
		{
			maps[nowUpPos.first][nowUpPos.second] = maps[nextUpPos.first][nextUpPos.second];
		}

		nowUpPos = nextUpPos;
	}

	pii nowDoPos = downPos;
	pii nextDoPos = downPos;
	int doDir = 0;

	while (true)
	{
		nextDoPos.first = nowDoPos.first + dirY[doD[doDir]];
		nextDoPos.second = nowDoPos.second + dirX[doD[doDir]];

		if (nextDoPos.first < doLimY || nextDoPos.first >= r ||
			nextDoPos.second < 0 || nextDoPos.second >= c)
		{
			doDir++;
			continue;
		}

		if (maps[nextDoPos.first][nextDoPos.second] == -1)
		{
			maps[nowDoPos.first][nowDoPos.second] = 0;
			break;
		}

		if (maps[nowDoPos.first][nowDoPos.second] != -1)
		{
			maps[nowDoPos.first][nowDoPos.second] = maps[nextDoPos.first][nextDoPos.second];
		}

		nowDoPos = nextDoPos;
	}
}

int getDustAmount(vector<vector<int>>& maps)
{
	int r = maps.size();
	int c = maps[0].size();

	int ret = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (maps[i][j] != -1)
				ret += maps[i][j];
		}
	}

	return ret;
}

int main()
{
	int r, c, t;
	cin >> r >> c >> t;

	vector<vector<int>> maps(r, vector<int>(c, 0));

	bool bInitUp = false;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == -1)
			{
				if (bInitUp == false)
				{
					upPos.first = i;
					upPos.second = j;
					bInitUp = true;
				}
				else
				{
					downPos = { i,j };
				}
			}
		}
	}

	while (t > 0)
	{
		Dusting(maps);
		Cleaning(maps);
		t--;
	}

	cout << getDustAmount(maps);

	return 0;
}