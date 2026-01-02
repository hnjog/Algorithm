#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(pii& a, pii& b)
	{
		return a.second > b.second;
	}
}; 

int getV(unordered_map<int, vector<pii>>& maps, int start, int to)
{
	priority_queue<pii, vector<pii>, Compare> pq;
	pq.push({ start,0 });

	unordered_set<int> visit;

	while (pq.empty() == false)
	{
		int now = pq.top().first;
		int nowC = pq.top().second;
		pq.pop();

		if (visit.find(now) != visit.end())
			continue;

		visit.insert(now);

		if (now == to)
			return nowC;

		for (pii& p : maps[now])
		{
			pq.push({ p.first,nowC + p.second });
		}
	}

	return -1;
}

int main()
{
	int n, m;
	cin >> n >> m;

	unordered_map<int, vector<pii>> maps;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		maps[a].push_back({ b,c });
		maps[b].push_back({ a,c });
	}

	int s, t;
	cin >> s >> t;

	cout << getV(maps, s, t);

	return 0;
}