#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>

using namespace std;

unordered_map<int, vector<int>> g;
vector<int> visit;


int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m, r;
	cin >> n >> m >> r;

	visit = vector<int>(n + 1, 0);

	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;

		if (g.find(s) == g.end())
			g[s] = vector<int>();

		g[s].push_back(e);

		if (g.find(e) == g.end())
			g[e] = vector<int>();

		g[e].push_back(s);
	}

	for (auto& p : g)
	{
		sort(p.second.begin(), p.second.end(), greater<int>());
	}

	int idx = 1;
	queue<int> q;
	q.push(r);
	
	while (q.empty() == false)
	{
		int f = q.front();
		q.pop();
		if (visit[f] > 0)
			continue;

		visit[f] = idx++;
		
		for (int val : g[f])
			q.push(val);
	}

	for (int i = 1; i <= n; i++)
	{
		cout << visit[i] << '\n';
	}
}