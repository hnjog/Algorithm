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

bool Union(vector<int>& pv, int a,int b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;

	pv[a] = b;

	return true;
}

struct edge
{
	int s, t, cost;
};

int main()
{
	while (true)
	{
		int m, n;
		cin >> m >> n;

		if (m == 0 && n == 0)
			break;

		vector<int> pv(m);
		for (int i = 0; i < m; i++)
			pv[i] = i;

		vector<edge> edges(n);
		int full = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> edges[i].s >> edges[i].t >> edges[i].cost;
			full += edges[i].cost;
		}

		sort(edges.begin(), edges.end(), []
		(const auto& a, const auto& b)
			{
				return a.cost < b.cost;
			});

		int ans = 0;
		for (edge& e : edges)
		{
			if (Union(pv, e.s, e.t))
			{
				ans += e.cost;
			}
		}

		cout << full - ans << '\n';
	}
	

	return 0;
}