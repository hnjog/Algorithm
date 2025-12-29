#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

vector<int> getPath(vector<vector<pii>>& maps, int start, int end)
{
	vector<int> result;
	result.push_back(start);

	int next = maps[start][end].first;

	bool bFind = true;

	while (next != end)
	{
		result.push_back(next);

		if (next == maps[next][end].first)
		{
			bFind = false;
			break;
		}
		next = maps[next][end].first;
	}

	result.push_back(end);

	if (bFind == false)
		result.clear();

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	const int vv = 1e9;

	vector<vector<pii>> maps(n + 1, vector<pii>(n + 1, { 0,vv }));

	for (int i = 0; i <= n; i++)
	{
		maps[i][i].first = i;
		maps[i][i].second = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (maps[a][b].second > c)
		{
			maps[a][b].first = b;
			maps[a][b].second = c;
		}
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
			if (maps[i][j].second == vv)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << maps[i][j].second << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				cout << 0 << '\n';
				continue;
			}

			vector<int> r = getPath(maps, i, j);

			cout << r.size() << ' ';
			for (int p : r)
			{
				cout << p << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}