#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>

using namespace std;

typedef pair<int, int> pii;

int n,m,x;

struct infos
{
	int now;
	int nowCost;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b) const
	{
		return a.nowCost > b.nowCost;
	}
};

int bfs(unordered_map<int, vector<pii>>& roads, int start, int to)
{
	priority_queue<infos,vector<infos>,Compare> pq;

	pq.push({ start,0 });

	vector<int> saved(n + 1,INT_MAX);
	int ret = 0;

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		int nowCost = pq.top().nowCost;
		pq.pop();

		if (saved[now] < nowCost)
			continue;

		saved[now] = nowCost;

		if (now == to)
		{
			return nowCost;
		}

		for (auto p : roads[now])
		{
			pq.push({ p.first,nowCost + p.second });
		}
	}

	return ret;
}

int main()
{
	cin >> n >> m >> x;

	unordered_map<int, vector<pii>> roads;

	for (int i = 0; i < m; i++)
	{
		int start, to, cost;
		cin >> start >> to >> cost;

		roads[start].push_back({ to,cost });
	}

	int maxV = 0;

	for (int i = 1; i <= n; i++)
	{
		int v1 = bfs(roads, i, x);
		int v2 = bfs(roads, x, i);
		if (v1 + v2 > maxV)
			maxV = v1 + v2;
	}

	cout << maxV;

	return 0;
}