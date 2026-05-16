#include <vector>
#include <unordered_map>
#include <queue>
#include <limits.h>

using namespace std;

struct infos
{
	int now;
	int cost;
};

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	unordered_map<int, vector<int>> maps;

	for (auto& ed : edge)
	{
		int start = ed[0];
		int end = ed[1];
		maps[start].push_back(end);
		maps[end].push_back(start);
	}

	vector<int> visited(n + 1, INT_MAX);
	int bestV = 0;

	queue<infos> q;
	q.push({ 1,0 });

	while (q.empty() == false)
	{
		int now = q.front().now;
		int cost = q.front().cost;
		q.pop();

		if (visited[now] <= cost)
			continue;

		visited[now] = cost;

		if (cost > bestV)
			bestV = cost;

		for (int next : maps[now])
		{
			q.push({ next,cost + 1 });
		}
	}

	for (int v : visited)
	{
		if (v == bestV)
			answer++;
	}

	return answer;
}