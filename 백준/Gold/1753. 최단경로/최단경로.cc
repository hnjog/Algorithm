#include<iostream>
#include<unordered_map>
#include<vector>
#include<limits.h>
#include<queue>

using namespace std;

struct infos
{
	int now;
	int nowCost;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		if (a.nowCost == b.nowCost)
			return a.now > b.now;

		return a.nowCost > b.nowCost;
	}
};

void bfs(unordered_map<int, vector<pair<int, int>>>& umaps, vector<int>& vec,int start)
{
	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ start,0 });

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		int nowCost = pq.top().nowCost;
		pq.pop();

		if (nowCost >= vec[now - 1])
			continue;

		vec[now-1] = nowCost;

		for (const auto& v : umaps[now])
		{
			pq.push({ v.first,nowCost + v.second });
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int v, e, start;
	cin >> v >> e >> start;

	unordered_map<int, vector<pair<int,int>>> umaps;
	
	vector<int> vec(v, INT_MAX);

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		umaps[u].push_back({ v,w });
	}

	bfs(umaps, vec, start);

	for (int i = 0; i < v; i++)
	{
		if (vec[i] == INT_MAX)
			cout << "INF" << '\n';
		else
			cout << vec[i] << '\n';
	}
}