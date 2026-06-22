#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<limits.h>

using namespace std;

const int dirY[8] = { -1,-1,-1,0,0,1,1,1 };
const int dirX[8] = { -1,0,1,-1,1,1,0,-1 };

int GetCounts(vector<vector<int>>& maps, int checkY, int checkX)
{
	if (maps[checkY][checkX] == -1)
		return -1;

	int n = maps.size();
	int ret = 0;

	for (int i = 0; i < 8; i++)
	{
		int ny = checkY + dirY[i];
		int nx = checkX + dirX[i];

		if (ny < 0 || ny >= n ||
			nx < 0 || nx >= n)
			continue;

		if (maps[ny][nx] == -1)
			ret++;
	}

	return ret;
}

void FindCheck(vector<vector<int>>& maps, int checkY, int checkX, vector<vector<bool>>& visit)
{
	if (maps[checkY][checkX] < 0)
		return;

	struct pos
	{
		int y, x;
	};

	int n = maps.size();

	queue<pos> q;

	q.push({ checkY,checkX });

	while (q.empty() == false)
	{
		int nowy = q.front().y;
		int nowx = q.front().x;
		q.pop();

		if (nowy < 0 || nowy >= n ||
			nowx < 0 || nowx >= n)
			continue;

		if (maps[nowy][nowx] < 0)
			continue;

		if (visit[nowy][nowx])
			continue;

		visit[nowy][nowx] = true;

		if (maps[nowy][nowx] == 0)
		{
			for (int i = 0; i < 8; i++)
			{
				q.push({ nowy + dirY[i], nowx + dirX[i] });
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<vector<int>> maps(n, vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < n; j++)
			{
				if (str[j] == '*')
					maps[i][j] = -1;
				else
					maps[i][j] = INT_MAX;
			}
		}

		int count = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps[i][j] = GetCounts(maps, i, j);
			}
		}

		vector<vector<bool>> visit(n, vector<bool>(n, false));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps[i][j] == 0 &&
					visit[i][j] == false)
				{
					FindCheck(maps, i, j, visit);
					count++;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps[i][j] > 0 &&
					visit[i][j] == false)
				{
					count++;
					visit[i][j] = true;
				}
			}
		}

		cout << '#' << test_case << ' ' << count << '\n';
	}
	return 0;
}