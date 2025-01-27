#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>

using namespace std;

struct pos
{
	int p;
	int count;
};

int bfs(int n, int k)
{
	queue<pos> q;
	q.push({ n,0 });

	vector<int> dp(100001, INT_MAX);
	dp[n] = 0;

	while (q.empty() == false)
	{
		pos p = q.front();
		q.pop();

		if (p.p < 0 || p.p > 100000)
			continue;

		if (dp[p.p] < p.count)
			continue;

		dp[p.p] = p.count;

		if (p.p == k)
			return p.count;

		q.push({ p.p - 1,p.count + 1 });;
		q.push({ p.p + 1,p.count + 1 });;
		q.push({ p.p * 2,p.count + 1 });;
	}

	return -1;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);
}