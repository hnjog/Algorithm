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
	int n, m;
	cin >> n >> m;

	vector<edge> edges;
	vector<int> parents(n+1);

	for (int i = 0; i < n + 1; i++)
	{
		parents[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		edge e;
		cin >> e.s;
		cin >> e.t;
		cin >> e.cost;

		edges.push_back(e);
	}

	sort(edges.begin(), edges.end(), []
	(const edge& a, const edge& b)
		{
			return a.cost < b.cost;
		});

	long answer = 0;
	long bestCost = 0;

	for (edge& e : edges)
	{
		if (Union(parents, e.s, e.t))
		{
			answer += e.cost;
			if (bestCost < e.cost)
				bestCost = e.cost;
		}
	}

	cout << answer - bestCost;
	return 0;
}