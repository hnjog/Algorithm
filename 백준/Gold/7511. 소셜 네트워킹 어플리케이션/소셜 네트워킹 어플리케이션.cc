#include<iostream>
#include<vector>

using namespace std;

int FindParent(vector<int>& pv, int x)
{
	if (pv[x] == x)
		return x;

	return pv[x] = FindParent(pv, pv[x]);
}

bool Union(vector<int>& pv, int a, int b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;	

	pv[a] = b;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	int idx = 1;
	while (idx <= t)
	{
		int n, k;
		cin >> n >> k;

		vector<int> pv(n);
		for (int i = 0; i < n; i++)
			pv[i] = i;

		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			Union(pv, a, b);
		}

		int m;
		cin >> m;

		cout << "Scenario " << idx << ":" << '\n';
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			if (FindParent(pv, a) == FindParent(pv, b))
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}

		cout << '\n';

		idx++;
	}

	return 0;
}