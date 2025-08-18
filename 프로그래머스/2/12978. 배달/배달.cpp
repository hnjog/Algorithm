#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<limits.h>

using namespace std;

typedef pair<int, int> pii;

struct info
{
	int now;
	int nowCost;
};

struct Compare
{
	bool operator()(const info& a, const info& b)
	{
		return a.nowCost < b.nowCost;
	}
};

const int start = 1;

bool isTime(unordered_map<int, vector<pii>>& graphs, vector<int>& dp, int k, int to)
{
	if (dp[to] <= k)
		return true;

	priority_queue<info, vector<info>, Compare> pq;
	pq.push({ start,0 });

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		int nowCost = pq.top().nowCost;
		pq.pop();

		if (nowCost > dp[now])
			continue;

		dp[now] = nowCost;

		if (nowCost > k)
			continue;

		if (now == to)
			return true;

		for (auto& g : graphs[now])
		{
			pq.push({ g.first,nowCost + g.second });
		}
	}

	return false;
}

// 마을 개수, 각 마을 연결 도로, 배달 제한 시간
int solution(int N, vector<vector<int>> road, int K) 
{
	int answer = 0;

	unordered_map<int, vector<pii>> graphs;

	for (auto& r : road)
	{
		int start = r[0];
		int to = r[1];
		int cost = r[2];

		graphs[start].push_back({ to,cost });
		graphs[to].push_back({ start,cost });
	}

	vector<int> dp(N + 1, INT_MAX);

	for (int i = 1; i <= N; i++)
	{
		if (isTime(graphs, dp, K, i))
		{
			answer++;
		}
	}

	return answer;
}