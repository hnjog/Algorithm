#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>

using namespace std;

int n, m;
int start, target;

struct infos
{
	int now;
	int nowCount;
	int nowCost;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		return a.nowCost > b.nowCost;
	}
};

void func(unordered_map<int, vector<pair<int, int>>>& umaps)
{
	// 이전에 방문한 노드와 그 비용
	// 이걸 통해 역추적할 예정
	vector<pair<int, int>> visit(n + 1);

	for (auto& p : visit)
	{
		p.first = 0;
		p.second = INT_MAX;
	}

	visit[start] = { start,0 };

	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ start,1,0 });

	int aCost = 0;
	int aCount = 0;

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		int nowCount = pq.top().nowCount;
		int nowCost = pq.top().nowCost;
		pq.pop();

		if (now == target)
		{
			aCost = nowCost;
			aCount = nowCount;
			break;
		}

		if (umaps.find(now) == umaps.end())
			continue;

		for (auto& p : umaps[now])
		{
			int next = p.first;
			int nCost = p.second;

			if (visit[next].second <= nowCost + nCost)
				continue;

			visit[next].first = now;
			visit[next].second = nowCost + nCost;

			pq.push({ p.first,nowCount + 1, nowCost + p.second });
		}
	}

	cout << aCost << '\n';
	cout << aCount << '\n';

	vector<int> v;
	int idx = target;
	for (int i = 0; i < aCount; i++)
	{
		v.push_back(idx);
		idx = visit[idx].first;
	}

	for (auto i = v.rbegin(); i != v.rend(); i++)
		cout << *i << ' ';
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	unordered_map<int, vector<pair<int, int>>> umaps;
	umaps.reserve(n);

	for (int i = 0; i < m; i++)
	{
		int s, t, c;
		cin >> s >> t >> c;
		umaps[s].push_back({ t,c });
	}

	cin >> start >> target;

	func(umaps);

	return 0;
}