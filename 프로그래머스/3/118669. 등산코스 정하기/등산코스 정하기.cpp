#include <vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<limits.h>
#include<queue>

using namespace std;

struct Edge
{
	int target;
	int cost;
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
	vector<int> dp(n + 1, INT_MAX);
	answer.push_back(INT_MAX);
	answer.push_back(INT_MAX);

	sort(gates.begin(), gates.end());
	sort(summits.begin(), summits.end());

	unordered_map<int, vector<Edge>> m;
	for (const auto& path : paths)
	{
		int start = path[0];
		int end = path[1];
		int cost = path[2];

		if (m.find(start) == m.end())
			m[start] = vector<Edge>();

		m[start].push_back({ end,cost });

		if (m.find(end) == m.end())
			m[end] = vector<Edge>();

		m[end].push_back({ start,cost });
	}

	// 비용 순으로 정렬시키기
	for (auto& p : m)
	{
		sort(p.second.begin(), p.second.end(), [](const Edge& a, const Edge& b) {
			if (a.cost == b.cost)
				return a.target < b.target;
			return a.cost < b.cost;
			});
	}

	unordered_set<int> gs(gates.begin(), gates.end());
	unordered_set<int> ss(summits.begin(), summits.end());

	struct node
	{
		int end, cost;
	};


	struct Compare
	{
		bool operator() (const node& a, const node& b)
		{
			if (a.cost == b.cost)
				return a.end > b.end;

			return a.cost > b.cost;
		}
	};

	priority_queue<node, vector<node>, Compare> pq;

	for (int g : gates)
	{
		dp[g] = 0;
		pq.push({g,0});
	}

	vector<bool> visited(n + 1, false);

	while (pq.empty() == false)
	{
		auto n = pq.top();
		pq.pop();

		// 이미 더 좋은 상황으로 방문됨
		if (n.cost > dp[n.end])
			continue;

		if (visited[n.end] == true)
			continue;

		dp[n.end] = n.cost;
		visited[n.end] = true;

		// 도착
		if (ss.find(n.end) != ss.end())
		{
			if (answer[1] > n.cost || (answer[1] == n.cost && answer[0] > n.end))
			{
				answer[0] = n.end;
				answer[1] = n.cost;
			}

			visited[n.end] = false;
			continue;
		}

		for (const Edge& v : m[n.end])
		{
			int cost = max( n.cost,v.cost);
			pq.push({ v.target,cost });
		}
	}

	return answer;
}