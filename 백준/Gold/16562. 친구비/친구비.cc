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

struct edge
{
	int s, t, cost;
};

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> parent(n + 1,0);
	vector<edge> edges;

	for (int i = 0; i < n; i++)
	{
		edge e;
		cin >> e.cost;
		e.s = 0;
		e.t = i + 1;
		
		edges.push_back(e);
		parent[i + 1] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		Union(parent, t1, t2);
	}

	sort(edges.begin(), edges.end(), [](auto& a, auto& b) {return a.cost < b.cost; });

	int ans = 0;

	for (auto& e : edges)
	{
		if (Union(parent, e.s, e.t))
		{
			ans += e.cost;
		}
	}

	if (ans > k)
		cout << "Oh no";
	else
		cout << ans;

	return 0;
}