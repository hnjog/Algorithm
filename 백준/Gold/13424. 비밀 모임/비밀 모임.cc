#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		t--;

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
			maps[b][a] = c;
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

		vector<int> fv(k);

		for (int i = 0; i < k; i++)
		{
			cin >> fv[i];
			fv[i]--;
		}

		int num = 0;
		int nV = 1e9;

		for (int i = 0; i < n; i++)
		{
			int sum = 0;

			for (int j = 0; j < k; j++)
			{
				sum += maps[i][fv[j]];
			}

			if (sum < nV)
			{
				num = i;
				nV = sum;
			}
		}

		num++;

		cout << num << '\n';
	}

	return 0;
}