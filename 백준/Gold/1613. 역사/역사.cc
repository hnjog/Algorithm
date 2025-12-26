#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	const int initV = 1e9;

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

	int s;
	cin >> s;

	vector<pii> query;

	for (int i = 0; i < s; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		query.push_back({ a,b });
	}

	for (pii& p : query)
	{
		int a = p.first;
		int b = p.second;

		if (maps[a][b] == initV &&
			maps[b][a] == initV)
		{
			cout << 0 << '\n';
		}
		else if (maps[a][b] == initV)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}

	return 0;
}