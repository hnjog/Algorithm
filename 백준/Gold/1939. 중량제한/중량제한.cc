#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>

using namespace std;

int n, m;

struct nodeInfo
{
	int now;
	int prev;
	int nowValue;
};

struct Compare
{
	bool operator()(const nodeInfo& a, const nodeInfo& b)
	{
		return a.nowValue < b.nowValue;
	}
};

int find(vector<int>& pv,int x)
{
	if (pv[x] == x)
		return x;

	return pv[x] = find(pv, pv[x]);
}

void Union(vector<int>& pv, int a, int b)
{
	a = find(pv, a);
	b = find(pv, b);

	if (a != b)
		pv[a] = b;
}

int getMaxV(unordered_map<int, unordered_map<int, int>>& maps, int start, int end)
{
	vector<int> pv(n + 1);
	for (int i = 0; i <= n; i++)
		pv[i] = i;

	priority_queue<nodeInfo, vector<nodeInfo>, Compare> pq;
	pq.push({ start,0,INT_MAX });

	int ret = 0;

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		int prev = pq.top().prev;
		int nowV = pq.top().nowValue;
		pq.pop();

		// 값 큰 위주로 돌고 있는데 이미 반환 예정값보다 작다면 더 돌필요 없음
		if (ret > nowV)
			break;
		
		if (now == end)
		{
			ret = nowV;
			continue;
		}

		// 이미 방문한 곳인디?
		if (find(pv, now) == find(pv, prev))
			continue;

		Union(pv, now, prev);

		for (auto& p : maps[now])
		{
			int n = p.first;
			int nV = p.second;
			if (nV > nowV)
				nV = nowV;

			pq.push({ n,now,nV });
		}
	}

	return ret;
}

int main()
{
	cin >> n >> m;

	unordered_map<int, unordered_map<int,int>> maps;

	for (int i = 0; i < m; i++)
	{
		int s, t, c;
		cin >> s >> t >> c;

		if (maps[s][t] < c)
			maps[s][t] = c;

		if (maps[t][s] < c)
			maps[t][s] = c;
	}

	int s, t;
	cin >> s >> t;

	cout << getMaxV(maps, s, t);

	return 0;
}