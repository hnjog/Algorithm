#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dist(n, vector<int>(n, 1e9));

	for (int i = 0; i < n; i++)
		dist[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		if (c == 0)
		{
			dist[a][b] = 0;
			dist[b][a] = 1;
		}
		else
		{
			dist[a][b] = 0;
			dist[b][a] = 0;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int k;
	cin >> k;

	vector<pair<int, int>> kv(k);

	for (int i = 0; i < k; i++)
	{
		cin >> kv[i].first >> kv[i].second;
		kv[i].first--;
		kv[i].second--;
	}

	for (int i = 0; i < k; i++)
	{
		int s = kv[i].first;
		int e = kv[i].second;

		cout << dist[s][e] << '\n';
	}

	return 0;
}