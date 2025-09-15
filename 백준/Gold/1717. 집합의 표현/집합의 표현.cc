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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> pv(n+1);
	for (int i = 0; i <= n; i++)
		pv[i] = i;

	for (int i = 0; i < m; i++)
	{
		int s, s1, s2;
		cin >> s >> s1 >> s2;

		if (s == 0)
		{
			Union(pv, s1, s2);
		}
		else
		{
			int s1p = find(pv, s1);
			int s2p = find(pv, s2);
			if (s1p == s2p)
			{
				cout << "YES" << '\n';
			}
			else
			{
				cout << "NO" << '\n';
			}
		}
	}

	return 0;
}