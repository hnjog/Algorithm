#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<set>
#include<limits.h>

using namespace std;

int n, m, t1, s, g, h;

struct pos
{
	int now;
	int nowCost;
};

struct Compare
{
	bool operator()(const pos& a, const pos& b)
	{
		return a.nowCost > b.nowCost;
	}
};

int wayValue(unordered_map<int, vector<pair<int, int>>>& umaps, int start, int target)
{
	priority_queue<pos, vector<pos>, Compare> pq;
	pq.push({ start,0 });

	vector<int> dp(n + 1, INT_MAX);

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		int nowCost = pq.top().nowCost;
		pq.pop();

		if (dp[now] <= nowCost)
			continue;

		dp[now] = nowCost;

		if (now == target)
		{
			return nowCost;
		}

		for (auto& p : umaps[now])
		{
			pq.push({ p.first,nowCost + p.second });
		}
	}

	return INT_MAX;
}

void findWay(unordered_map<int, vector<pair<int, int>>>& umaps, set<int>& nomiSet, set<int>& answers)
{
	for (int n : nomiSet)
	{
		long stg = wayValue(umaps, s, g);
		long gth = wayValue(umaps, g, h);
		long htn = wayValue(umaps, h, n);

		long v1 = stg + gth + htn;

		long sth = wayValue(umaps, s, h);
		long htg = wayValue(umaps, h, g);
		long gtn = wayValue(umaps, g, n);

		long v2 = sth + htg + gtn;

		long v3 = wayValue(umaps, s, n);

		if (v3 == INT_MAX)
			continue;

		if(v3 == v1 ||
			v3 == v2)
			answers.insert(n);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n >> m >> t1 >> s >> g >> h;

		unordered_map<int, vector<pair<int, int>>> umaps;
		// 도로 정보
		for (int j = 0; j < m; j++)
		{
			int a, b, d;
			cin >> a >> b >> d;

			umaps[a].push_back({ b,d });
			umaps[b].push_back({ a,d });
		}

		set<int> f1, f2;
		// 목적지 후보
		for (int j = 0; j < t1; j++)
		{
			int x;
			cin >> x;
			f1.insert(x);
		}

		findWay(umaps, f1, f2);

		for (int f : f2)
		{
			cout << f << ' ';
		}

		cout << '\n';
	}
}
