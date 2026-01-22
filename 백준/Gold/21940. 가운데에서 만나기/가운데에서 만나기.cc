#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> maps(n, vector<int>(n, 1e9));
	for (int i = 0; i < n; i++)
		maps[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		maps[a][b] = c;
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

	int k;
	cin >> k;

	vector<int> cs(k);
	for (int i = 0; i < k; i++)
	{
		cin >> cs[i];
		cs[i]--;
	}

	vector<int> sums(n);

	int mv = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		int tv = 0;
		for (int j = 0; j < k; j++)
		{
			int tt = maps[cs[j]][i] + maps[i][cs[j]];
			if (tt > tv)
				tv = tt;
		}

		sums[i] = tv;

		if (tv < mv)
			mv = tv;
	}

	for (int i = 0; i < n; i++)
	{
		if (sums[i] == mv)
		{
			cout << i + 1 << ' ';
		}
	}

	return 0;
}