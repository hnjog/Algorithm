#include<iostream>
#include<unordered_map>
#include<vector>
#include<limits.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<long long>> distance(n + 1, vector<long long>(n + 1, LONG_MAX));

	for (int i = 0; i < m; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		distance[a][b] = min(distance[a][b], c);
		//distance[b][a] = min(distance[b][a], c);
	}

	for (int i = 0; i <= n; i++)
	{
		distance[i][i] = 0;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (distance[i][k] == LONG_MAX || distance[k][j] == LONG_MAX)
					continue;

				if (distance[i][j] > distance[i][k] + distance[k][j])
					distance[i][j] = distance[i][k] + distance[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (distance[i][j] == LONG_MAX)
				cout << 0 << ' ';
			else
				cout << distance[i][j] << ' ';
		}
		cout << '\n';
	}

}