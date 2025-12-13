#include<iostream>
#include<vector>
#include<algorithm>

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

struct edges
{
	int s, t;
	long cost;
};

int main()
{
	int n;
	cin >> n;

	vector<int> pv(n);
	for (int i = 0; i < n; i++)
		pv[i] = i;

	vector<edges> ev;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long c;
			cin >> c;

			if (i == j)
				continue;

			edges e;

			int s = i;
			int t = j;

			if (s < t)
				swap(s, t);

			e.s = s;
			e.t = t;
			e.cost = c;

			ev.push_back(e);
		}
	}

	sort(ev.begin(), ev.end(), []
	(const edges& a, const edges& b)
		{
			return a.cost < b.cost;
		}
	);

	long ans = 0;

	for (edges& e : ev)
	{
		if (Union(pv, e.s, e.t))
		{
			ans += e.cost;
		}
	}

	cout << ans;

	return 0;
}