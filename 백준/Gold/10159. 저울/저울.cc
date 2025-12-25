#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	const int inV = 1e9;

	vector<vector<int>> maps(n, vector<int>(n, inV));

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

	for (int i = 0; i < n; i++)
	{
		int count = 0;

		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			if (maps[i][j] != inV ||
				maps[j][i] != inV)
				count++;
		}

		cout << n - count - 1 << '\n';
	}


	return 0;
}