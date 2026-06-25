#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

int Dfs(const vector<vector<int>>& maps, vector<vector<int>>& visit, int y, int x)
{
	if (visit[y][x] > 1)
		return visit[y][x];

	int n = maps.size();
	int count = 1;
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dirY[i];
		int nx = x + dirX[i];

		if (ny < 0 || ny >= n ||
			nx < 0 || nx >= n)
			continue;

		if (maps[ny][nx] == maps[y][x] + 1)
			count += Dfs(maps, visit, ny, nx);
	}

	visit[y][x] = count;
	return count;
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
		vector<vector<int>> visit(n, vector<int>(n,0));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> maps[i][j];
			}
		}

		int val = 1;
		int vc = 1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int tv = Dfs(maps,visit, i, j);
				if (tv > vc)
				{
					vc = tv;
					val = maps[i][j];
					continue;
				}

				if (tv == vc)
				{
					val = min(val, maps[i][j]);
				}
			}
		}

		cout << '#' << test_case << ' ' << val << ' ' << vc << '\n';
	}
	return 0;
}