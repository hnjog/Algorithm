#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(pii& a, pii& b)
	{
		return a.second < b.second;
	}
};

int GetMaxV(const int n,const int m, const int s, const int e, unordered_map<int, vector<pii>>& maps)
{
	vector<int> visited(n+1, 0);

	priority_queue<pii, vector<pii>, Compare> pq;
	pq.push({ s,1e9 });

	while (pq.empty() == false)
	{
		int now = pq.top().first;
		int nowW = pq.top().second;
		pq.pop();

		if (visited[now] >= nowW)
			continue;

		visited[now] = nowW;

		if (now == e)
			return nowW;

		for (const pii& p : maps[now])
		{
			pq.push({ p.first,min(nowW,p.second) });
		}
	}

	return 0;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int s, e;
	cin >> s >> e;

	unordered_map<int, vector<pii>> maps;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		maps[a].push_back({ b,c });
		maps[b].push_back({ a,c });
	}

	cout << GetMaxV(n, m, s, e, maps);

	return 0;
}