#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

struct infos
{
	int pos;
	int cost;
};

int n, k;

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		return a.cost > b.cost;
	}
};

int bfs(int n, int k)
{
	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ n,0 });

	vector<int> dp(100001, INT_MAX);

	while (pq.empty() == false)
	{
		int nowPos = pq.top().pos;
		int nowCost = pq.top().cost;
		pq.pop();

		if (nowPos >= 100001 || nowPos < 0)
			continue;

		if (nowCost >= dp[nowPos])
			continue;

		dp[nowPos] = nowCost;

		if (nowPos == k)
			return nowCost;

		if (nowPos != 0)
			pq.push({ nowPos * 2,nowCost });

		pq.push({ nowPos + 1,nowCost + 1 });
		pq.push({ nowPos - 1,nowCost + 1 });

	}

	return -1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	cout << bfs(n, k);
}