#include <vector>
#include<unordered_map>
#include<queue>

using namespace std;

struct Compare
{
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		if (a.second == b.second)
			return a.first > b.first;

		return a.second > b.second;
	}
};

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 1;

	unordered_map<int, unordered_map<int, int>> maps;

	for (const auto& r : road)
	{
		int start = r[0];
		int end = r[1];
		int cost = r[2];

		if (maps.find(start) == maps.end())
			maps[start] = unordered_map<int, int>();

		// 중복 값이 들어올 수 있음
		if (maps[start].find(end) != maps[start].end())
		{
			if (maps[start][end] > cost)
				maps[start][end] = cost;
		}
		else
		{
			maps[start][end] = cost;
		}

		if (maps.find(end) == maps.end())
			maps[end] = unordered_map<int, int>();

		if (maps[end].find(start) != maps[end].end())
		{
			if (maps[end][start] > cost)
				maps[end][start] = cost;
		}
		else
		{
			maps[end][start] = cost;
		}
	}


	// 각 도시의 값 구하기
	for (int i = 2; i <= N; i++)
	{
		int start = 1;
		int target = i;
		vector<bool> visited(N + 1, false);
		visited[0] = true;
		visited[1] = true;

		// BFS 탐색 (목적지, 비용)
		priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
		for (const auto& a : maps[start])
		{
			pq.push(a);
		}

		while (pq.empty() == false)
		{
			auto p = pq.top();
			pq.pop();

			int now = p.first;
			int nowCost = p.second;

			if (nowCost > K)
				continue;

			// 목적지 도착
			if (now == target)
			{
				if (nowCost <= K)
				{
					answer++;
					break;
				}

				continue;
			}

			// 이미 방문함
			if (visited[now] == true)
				continue;

			visited[now] = true;

			for (const auto& a : maps[now])
			{
				pq.push({ a.first,a.second + nowCost });
			}
		}

	}

	return answer;
}