#include<iostream>
#include<vector>

using namespace std;

int FindParent(vector<int>& pv, int x)
{
	if (pv[x] == x)
		return x;

	return pv[x] = FindParent(pv, pv[x]);
}

bool Union(vector<int>& pv, int a,int b)
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
	int n, m;
	cin >> n >> m;
	vector<int> pv(n);

	for (int i = 0; i < n; i++)
		pv[i] = i;

	for (int i = 0; i < m; i++)
	{
		int s, t;
		cin >> s >> t;
		s--;
		t--;

		Union(pv,s, t);
	}

	int ans = 0;

	int now = 0;
	int prev = -1;

	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		now = t - 1;

		if (prev == -1)
		{
			prev = now;
			continue;
		}

		if (FindParent(pv, now) != FindParent(pv, prev))
		{
			ans++;
			prev = now;
		}

	}

	cout << ans;

	return 0;
}