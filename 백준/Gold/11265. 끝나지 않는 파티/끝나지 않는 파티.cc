#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<long>> maps(n, vector<long>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maps[i][j];
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (maps[i][j] > maps[i][k] + maps[k][j])
					maps[i][j] = maps[i][k] + maps[k][j];
			}
		}
	}

	struct infos
	{
		long s, t, c;
	};

	vector<infos> ords(m);

	for (int i = 0; i < m; i++)
	{
		cin >> ords[i].s >> ords[i].t >> ords[i].c;
		ords[i].s--;
		ords[i].t--;
	}

	for (int i = 0; i < m; i++)
	{
		long s = ords[i].s;
		long t = ords[i].t;
		long c = ords[i].c;

		if (c >= maps[s][t])
		{
			cout << "Enjoy other party" << '\n';
		}
		else
		{
			cout << "Stay here" << '\n';
		}

	}

	return 0;
}