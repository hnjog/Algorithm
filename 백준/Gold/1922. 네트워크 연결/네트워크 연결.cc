#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<limits.h>
#include<queue>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(const pii& a, const pii& b)
	{
		return a.second > b.second;
	}
};

int prim(unordered_map<int, vector<pii>>& maps, int start, int n)
{
	int result = 0;

	priority_queue<pii, vector<pii>, Compare> pq;

	unordered_set<int> visit;
	visit.insert(start);

	for (auto& p : maps[start])
	{
		pq.push(p);
	}

	while (pq.empty() == false)
	{
		int next = pq.top().first;
		int nextCost = pq.top().second;
		pq.pop();

		if (visit.find(next) != visit.end())
			continue;

		visit.insert(next);
		result += nextCost;

		if (visit.size() == n)
			break;

		for (auto& p : maps[next])
			pq.push(p);
	}

	return result;
}

int main()
{
	int n, m;
	cin >> n >> m;

	unordered_map<int, vector<pii>> maps;

	int st = 0, startCost = INT_MAX;

	for (int i = 0; i < m; i++)
	{
		int start, to, cost;
		cin >> start >> to >> cost;

		maps[start].push_back({ to,cost });
		maps[to].push_back({ start,cost });

		if (cost < startCost)
		{
			startCost = cost;
			st = start;
		}
	}

	cout << prim(maps, st,n);

	return 0;
}