#include<iostream>
#include<vector>

using namespace std;

const int initV = 1e9;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> maps(n, vector<int>(n, initV));

	for (int i = 0; i < n; i++)
		maps[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		maps[a][b] = 1;
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maps[i][j] = min(maps[i][j], maps[i][k] + maps[k][j]);
			}
		}
	}

	int count = 0;

	for (int i = 0; i < n; i++)
	{
		bool bFound = true;

		for (int j = 0; j < n; j++)
		{
			if (maps[i][j] == initV &&
				maps[j][i] == initV)
			{
				bFound = false;
				break;
			}
		}

		if (bFound)
			count++;
	}

	cout << count;

	return 0;
}