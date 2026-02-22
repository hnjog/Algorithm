#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int maxDis = min(n, m);

	vector<vector<int>> maps(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;

		for (int j = 0; j < m; j++)
		{
			maps[i][j] = t[j] - '0';
		}
	}

	int dis = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int d = maxDis; d > dis; d--)
			{
				if (i + d >= n ||
					j + d >= m)
					continue;

				int v = maps[i][j];
				if (maps[i + d][j] == v &&
					maps[i][j + d] == v &&
					maps[i + d][j + d] == v)
				{
					dis = d;
				}
			}
		}
	}

	dis++;
	cout << dis * dis;

	return 0;
}