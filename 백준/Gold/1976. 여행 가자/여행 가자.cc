#include<iostream>
#include<vector>

using namespace std;

int find(vector<int>& pv, int x)
{
	if (pv[x] == x)
		return x;

	return pv[x] = find(pv, pv[x]);
}

void Union(vector<int>& pv, int a, int b)
{
	a = find(pv, a);
	b = find(pv, b);

	if (a != b)
		pv[a] = b;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> parents(n + 1);
	for (int i = 0; i <= n; i++)
		parents[i] = i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int t;
			cin >> t;
			if (t == 1)
			{
				Union(parents, i, j);
			}
		}
	}

	int v = 0;

	bool bSuccess = true;

	for (int i = 1; i <= m; i++)
	{
		int t;
		cin >> t;
		if (v == 0)
			v = find(parents, t);
		else
		{
			if (v != find(parents, t))
			{
				bSuccess = false;
				break;
			}
		}
	}

	if (bSuccess)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}