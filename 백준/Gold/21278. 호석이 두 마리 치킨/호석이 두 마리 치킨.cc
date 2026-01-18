#include<iostream>
#include<vector>

using namespace std;

int getV(vector<vector<int>>& maps, int a, int b)
{
	int n = maps.size();

	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		ret += min(maps[a][i], maps[b][i]);
	}

	return ret;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> maps(n, vector<int>(n, 1e9));

	for (int i = 0; i < n; i++)
		maps[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;

		maps[a][b] = 1;
		maps[b][a] = 1;
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
	
	pair<int, int> p;
	int v = 1e9;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int t = getV(maps, i, j);
			if (t < v)
			{
				v = t;
				p.first = i;
				p.second = j;
			}
		}
	}

	cout << p.first + 1 << ' ' << p.second + 1 << ' ' << v * 2;

	return 0;
}