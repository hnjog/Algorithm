#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

struct infos
{
	int now;
	int useMoney;
	int smallV;
};

struct Compare
{
	bool operator()(infos& a, infos& b)
	{
		if (a.smallV == b.smallV)
			return a.useMoney > b.useMoney;

		return a.smallV > b.smallV;
	}
};

int GetV(const int n, const int start, const int target, const int money, unordered_map<int, vector<pii>>& maps)
{
	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ start,0,0 });

	vector<int> visited(n + 1, 1e9);

	while (pq.empty()== false)
	{
		int now = pq.top().now;
		int nowUM = pq.top().useMoney;
		int nowSV = pq.top().smallV;
		pq.pop();

		if (nowUM > money)
			continue;

		if (visited[now] <= nowUM)
			continue;

		visited[now] = nowUM;

		if (now == target)
			return nowSV;

		for (pii& p : maps[now])
		{
			pq.push({ p.first,nowUM + p.second, max(nowSV,p.second) });
		}
	}

	return -1;
}

int main()
{
	int n, m, start, target, money;
	cin >> n >> m >> start >> target >> money;

	unordered_map<int, vector<pii>> maps;
	maps.reserve(n);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		maps[a].push_back({ b,c });
		maps[b].push_back({ a,c });
	}

	cout << GetV(n, start, target, money, maps);

	return 0;
}