#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(pii& a, pii& b)
	{
		return a.second > b.second;
	}
};

vector<int> getV(unordered_map<int, vector<pii>>& maps, int n)
{
	priority_queue<pii, vector<pii>, Compare> pq;
	pq.push({ 1,0 });

	vector<int> visited(n + 1, 1e9);

	while (pq.empty() == false)
	{
		int now = pq.top().first;
		int nowc = pq.top().second;
		pq.pop();

		if (visited[now] <= nowc)
			continue;

		visited[now] = nowc;

		for (pii& p : maps[now])
		{
			pq.push({ p.first,nowc + p.second });
		}
	}

	return visited;
}

int main()
{
	int n, m;
	cin >> n >> m;

	struct edges
	{
		int s, t, cost;
	};

	vector<edges> ev(m);
	for (int i = 0; i < m; i++)
	{
		cin >> ev[i].s >> ev[i].t >> ev[i].cost;
		if (ev[i].s > ev[i].t)
			swap(ev[i].s, ev[i].t);
	}

	unordered_map<int, vector<pii>> maps;

	for (edges& e : ev)
	{
		maps[e.s].push_back({ e.t,e.cost });
		maps[e.t].push_back({ e.s,e.cost });
	}

	vector<pii> results;
	vector<int> dist = getV(maps, n);
	vector<int> visit(n + 1,-1);

	for (edges e : ev)
	{
		int u = e.s;
		int v = e.t;
		int w = e.cost;

		if (dist[u] + w == dist[v])
		{
			if (visit[v] == -1)
			{
				visit[v] = u;
				results.push_back({ u, v });
			}
		}
		else if (dist[v] + w == dist[u])
		{
			if (visit[u] == -1)
			{
				visit[u] = v;
				results.push_back({ v, u });
			}
		}
	}

	cout << results.size() << '\n';

	for (pii& p : results)
	{
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}