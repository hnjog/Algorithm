#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct nodeData
{
	int parent;
	bool bMan;
};

int FindParent(vector<nodeData>& pv, int x)
{
	if (pv[x].parent == x)
		return x;

	return pv[x].parent = FindParent(pv, pv[x].parent);
}

bool Union(vector<nodeData>& pv, int a, int b)
{
	if (pv[a].bMan == pv[b].bMan)
		return false;

	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;

	pv[a].parent = b;

	return true;
}

struct edge
{
	int s, t, cost;
};

int main()
{
	int n, m;
	cin >> n >> m;

	vector<nodeData> pv(n);
	vector<edge> ev(m);

	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if (c == 'M')
			pv[i].bMan = true;
		else
			pv[i].bMan = false;

		pv[i].parent = i;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> ev[i].s >> ev[i].t >> ev[i].cost;
		ev[i].s--;
		ev[i].t--;
	}

	sort(ev.begin(), ev.end(), []
	(const auto& a, const auto& b)
		{
			return a.cost < b.cost;
		});


	int ans = 0;
	int count = 0;

	for (edge& e : ev)
	{
		if (Union(pv, e.s, e.t))
		{
			ans += e.cost;
			count++;
		}
	}

	if (count == n - 1)
		cout << ans;
	else
		cout << -1;

	return 0;
}