#include<iostream>

using namespace std;

int maps[19][19];

const int dirY[4] = {0,1,1,1};
const int dirX[4] = {1,0,1,-1};

bool dfs(int v, int dir, int nowy, int nowx, int count)
{
	if (count >= 5)
	{
		int ny = dirY[dir] + nowy;
		int nx = dirX[dir] + nowx;

		if (ny < 0 || ny >= 19 ||
			nx < 0 || nx >= 19)
		{
			return true;
		}

		if (maps[ny][nx] == v)
		{
			return false;
		}

		return true;
	}


	int ny = dirY[dir] + nowy;
	int nx = dirX[dir] + nowx;

	if (ny < 0 || ny >= 19 ||
		nx < 0 || nx >= 19)
	{
		return false;
	}

	if (maps[ny][nx] != v)
	{
		return false;
	}

	return dfs(v, dir, ny, nx, count + 1);
}

int main()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> maps[i][j];
		}
	}

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (maps[i][j] != 0)
			{
				for (int d = 0; d < 4; d++)
				{
					int ty = i - dirY[d];
					int tx = j - dirX[d];
					if (ty >= 0 && ty < 19 &&
						tx >= 0 && tx < 19)
					{
						if (maps[ty][tx] == maps[i][j])
							continue;
					}

					if (dfs(maps[i][j], d, i, j, 1))
					{
						cout << maps[i][j] << '\n';
						if (d == 3)
						{
							cout << i + dirY[d] * 4 + 1 << ' ' << j + dirX[d] * 4 + 1;
						}
						else
						{
							cout << i + 1 << ' ' << j + 1;
						}

						return 0;
					}
				}
			}
		}
	}

	cout << 0;
	return 0;
}