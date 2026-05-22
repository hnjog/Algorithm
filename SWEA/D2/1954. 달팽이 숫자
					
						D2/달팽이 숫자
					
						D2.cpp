#include<iostream>
#include<vector>

using namespace std;

const int dirY[4] = { 0,1,0,-1 };
const int dirX[4] = { 1,0,-1,0 };

int GetNextDir(vector<vector<int>>& maps, int nowDir, int nowy, int nowx)
{
	int n = maps.size();

	int dir = nowDir;

	int ny = nowy + dirY[dir];
	int nx = nowx + dirX[dir];

	if (ny < 0 || ny >= n ||
		nx < 0 || nx >= n)
	{
		dir++;
		if (dir >= 4)
			dir = 0;
		return dir;
	}

	if (maps[ny][nx] != 0)
	{
		dir++;
		if (dir >= 4)
			dir = 0;
		return dir;
	}

	return dir;
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

		cout << '#' << test_case << '\n';

		vector<vector<int>> maps(n, vector<int>(n, 0));

		int y = 0, x = 0;
		int val = 1;
		int dir = 0;
		while (val <= n * n)
		{
			maps[y][x] = val;
			val++;

			dir = GetNextDir(maps, dir, y, x);
			y = y + dirY[dir];
			x = x + dirX[dir];
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << maps[i][j] << ' ';
			}
			cout << '\n';
		}

	}
	return 0;
}