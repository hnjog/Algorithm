#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

unordered_map<int, vector<int>> g;
vector<int> visit;

void dfs(int nowVisit, int& idx)
{
	if (visit[nowVisit] > 0)
		return;

	visit[nowVisit] = idx;
	idx++;

	for (const int s : g[nowVisit])
	{
		dfs(s, idx);
	}
}

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
	dfs(r,idx);

	for (int i = 1; i <= n; i++)
	{
		cout << visit[i] << '\n';
	}
}