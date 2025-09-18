#include<iostream>
#include<vector>

using namespace std;

const int lim = 5;
int n;

int move(vector<vector<long>>& maps, int dir)
{
	int bestV = 0;
	switch (dir)
	{
	case 0: // up
	{
		// 이동 페이즈
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp = i;
				while (temp < n &&
					maps[temp][j] == 0)
				{
					temp++;
				}

				if (temp == i)
					continue;

				if (temp == n)
					continue;

				maps[i][j] = maps[temp][j];
				maps[temp][j] = 0;
			}
		}

		// 한번 합치는 페이즈
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps[i][j] == maps[i + 1][j])
				{
					maps[i][j] *= 2;
					maps[i + 1][j] = 0;
				}

				if (maps[i][j] > bestV)
					bestV = maps[i][j];
			}
		}

		// 이동 페이즈
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int temp = i;
				while (temp < n &&
					maps[temp][j] == 0)
				{
					temp++;
				}

				if (temp == i)
					continue;

				if (temp == n)
					continue;

				maps[i][j] = maps[temp][j];
				maps[temp][j] = 0;
			}
		}
	}
		break;
	case 1: // down
	{
		// 이동 페이즈
		for (int i = n - 1; i > 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				int temp = i;
				while (temp >= 0 &&
					maps[temp][j] == 0)
				{
					temp--;
				}
				if (temp == i)
					continue;

				if (temp < 0)
					continue;

				maps[i][j] = maps[temp][j];
				maps[temp][j] = 0;
			}
		}

		// 한번 합치는 페이즈
		for (int i = n - 1; i > 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps[i][j] == maps[i - 1][j])
				{
					maps[i][j] *= 2;
					maps[i - 1][j] = 0;
				}

				if (maps[i][j] > bestV)
					bestV = maps[i][j];
			}
		}

		// 이동 페이즈
		for (int i = n - 1; i > 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				int temp = i;
				while (temp >= 0 && 
					maps[temp][j] == 0)
				{
					temp--;
				}
				if (temp == i)
					continue;

				if (temp < 0)
					continue;

				maps[i][j] = maps[temp][j];
				maps[temp][j] = 0;
			}
		}
	}
	break;
	case 2: // right
	{
		for (int j = n - 1; j > 0; j--)
		{
			for (int i = 0; i < n; i++)
			{
				int temp = j;
				while (temp >= 0
					&& maps[i][temp] == 0)
				{
					temp--;
				}

				if (temp == j)
					continue;

				if (temp < 0)
					continue;

				maps[i][j] = maps[i][temp];
				maps[i][temp] = 0;
			}
		}

		for (int j = n - 1; j > 0; j--)
		{
			for (int i = 0; i < n; i++)
			{
				if (maps[i][j] == maps[i ][j - 1])
				{
					maps[i][j] *= 2;
					maps[i][j - 1] = 0;
				}

				if (maps[i][j] > bestV)
					bestV = maps[i][j];
			}
		}

		for (int j = n - 1; j > 0; j--)
		{
			for (int i = 0; i < n; i++)
			{
				int temp = j;
				while (temp >= 0 
					&& maps[i][temp] == 0)
				{
					temp--;
				}

				if (temp == j)
					continue;

				if (temp < 0)
					continue;

				maps[i][j] = maps[i][temp];
				maps[i][temp] = 0;
			}
		}
	}
	break;
	case 3: // left
	{
		for (int j = 0; j < n - 1; j++)
		{
			for (int i = 0; i < n; i++)
			{
				int temp = j;
				while (temp < n &&
					maps[i][temp] == 0)
				{
					temp++;
				}

				if (temp == j)
					continue;

				if (temp == n)
					continue;

				maps[i][j] = maps[i][temp];
				maps[i][temp] = 0;
			}
		}

		for (int j = 0; j < n-1; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (maps[i][j] == maps[i][j + 1])
				{
					maps[i][j] *= 2;
					maps[i][j + 1] = 0;
				}

				if (maps[i][j] > bestV)
					bestV = maps[i][j];
			}
		}

		for (int j = 0; j < n - 1; j++)
		{
			for (int i = 0; i < n; i++)
			{
				int temp = j;
				while (temp < n &&
					maps[i][temp] == 0)
				{
					temp++;
				}

				if (temp == j)
					continue;

				if (temp  == n)
					continue;

				maps[i][j] = maps[i][temp];
				maps[i][temp] = 0;
			}
		}
	}
	break;
	}

	return bestV;
}

int recur(vector<vector<long>>& maps, int best, int count)
{
	if (count == lim)
	{
		return best;
	}

	for (int i = 0; i < 4; i++)
	{
		vector<vector<long>> origin = maps;
		best = max(best, move(maps, i));
		best = max(best, recur(maps, best, count + 1));
		maps = origin;
	}

	return best;
}

int main()
{
	cin >> n;

	vector<vector<long>> maps(n, vector<long>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> maps[i][j];

	if (n == 1)
		cout << maps[0][0];
	else
		cout << recur(maps, 0, 0);

	return 0;
}