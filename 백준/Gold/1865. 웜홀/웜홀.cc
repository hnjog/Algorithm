#include<iostream>
#include<vector>
#include<string>
#include<limits.h>

using namespace std;

struct edge
{
	int s, t, cost;
};

bool belmanFord(int n, vector<edge>& edges)
{
	vector<int> dist(n, 0);

	for (int i = 0; i < n; i++)
	{
		for (edge& e : edges)
		{
			int s = e.s;
			int t = e.t;
			int cost = e.cost;

			if (dist[t] > dist[s] + cost)
			{
				dist[t] = dist[s] + cost;
			}
		}
	}

	for (edge& e : edges)
	{
		int s = e.s;
		int t = e.t;
		int cost = e.cost;

		if (dist[t] > dist[s] + cost)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		int n, m, w;
		cin >> n >> m >> w;
		vector<edge> edges;

		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			s--;
			e--;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}

		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			s--;
			e--;
			edges.push_back({ s,e,-t });
		}

		if (belmanFord(n, edges))
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		t--;
	}

	return 0;
}