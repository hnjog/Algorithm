#include<iostream>
#include<unordered_map>
#include<vector>
#include<limits.h>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long ll;

struct infos
{
	int now;
	int nowCost;
	int prev;
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

int findWay(unordered_map<int, vector<pair<int, int>>>& umaps, const int v, int start, int target)
{
	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ start,0,start });

	vector<vector<int>> vec(v + 1, vector<int>(v + 1, INT_MAX));

	while (pq.empty() == false)
	{
		int prev = pq.top().prev;
		int now = pq.top().now;
		int nowCost = pq.top().nowCost;
		pq.pop();

		if (nowCost >= vec[prev][now] ||
			nowCost >= vec[now][prev])
			continue;

		vec[prev][now] = nowCost;
		vec[now][prev] = nowCost;

		if (now == target)
		{
			return nowCost;
		}

		for (const auto& v : umaps[now])
		{
			pq.push({ v.first,nowCost + v.second,now });
		}
	}

	return INT_MAX;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;

	unordered_map<int, vector<pair<int, int>>> umaps;
	

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		umaps[u].push_back({ v,w });
		umaps[v].push_back({ u,w });
	}

	int t1, t2;
	cin >> t1 >> t2;

	ll stt1 = findWay(umaps, v, 1, t1);
	ll t1tt2 = findWay(umaps, v, t1, t2);
	ll t2tv = findWay(umaps, v, t2, v);

	ll r1 = stt1 + t1tt2 + t2tv;

	ll stt2 = findWay(umaps, v, 1, t2);
	ll t2tt1 = findWay(umaps, v, t2, t1);
	ll t1tv = findWay(umaps, v, t1, v);

	ll r2 = stt2 + t2tt1 + t1tv;

	ll r = min(r1, r2);

	if (r >= INT_MAX)
		r = -1;

	cout << r;
}