#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>

using namespace std;

typedef pair<int, int> pii;

int n, m;

struct Compare
{
	bool operator()(const pii& a, const pii& b)
	{
		return a.second > b.second;
	}
};

int GetV(unordered_map<int, vector<pii>>& um)
{
	const int start = 1;

	vector<int> visit(n + 1, INT_MAX);

	priority_queue<pii, vector<pii>, Compare> pq;
	pq.push({ start,0 });

	while (pq.empty() == false)
	{
		int now = pq.top().first;
		int nowCost = pq.top().second;
		pq.pop();

		if (visit[now] <= nowCost)
			continue;

		visit[now] = nowCost;

		if (now == n)
			break;

		for (pii& p : um[now])
		{
			pq.push({ p.first, nowCost + p.second });
		}
	}

	return visit[n];
}

int main()
{
	cin >> n >> m;

	unordered_map<int, vector<pii>> um;

	for (int i = 0; i < m; i++)
	{
		int s, t, cost;
		cin >> s >> t >> cost;

		um[s].push_back({ t,cost });
		um[t].push_back({ s,cost });
	}

	cout << GetV(um);

	return 0;
}