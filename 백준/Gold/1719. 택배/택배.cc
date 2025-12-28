#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	const int vv = 1e9;

	vector<vector<pii>> maps(n + 1, vector<pii>(n + 1, { 0,vv }));

	for (int i = 0; i <= n; i++)
		maps[i][i].first = i;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		maps[a][b].first = b;
		maps[a][b].second = c;
		maps[b][a].first = a;
		maps[b][a].second = c;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (maps[i][j].second > maps[i][k].second + maps[k][j].second)
				{
					maps[i][j].first = maps[i][k].first;

					maps[i][j].second = maps[i][k].second + maps[k][j].second;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				cout << "- ";
				continue;
			}

			cout << maps[i][j].first << ' ';
		}

		cout << '\n';
	}

	return 0;
}