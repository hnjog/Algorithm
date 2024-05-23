#include <string>
#include <vector>
#include <unordered_map>
#include<limits.h>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

	// input 값 정리하기
	unordered_map<int, vector<pair<int, int>>> edges;
	for (const auto& fare : fares)
	{
		int begin = fare[0] - 1;
		int to = fare[1] - 1;
		int cost = fare[2];

		if (edges.find(begin) == edges.end())
		{
			edges[begin] = vector<pair<int, int>>();
		}

		edges[begin].push_back(make_pair(to, cost));

		if (edges.find(to) == edges.end())
		{
			edges[to] = vector<pair<int, int>>();
		}

		edges[to].push_back(make_pair(begin, cost));
	}

	const int limit = INT_MAX/10;
	vector<vector<int>> fw(n, vector<int>(n, limit));

	// 플로이드 - 워셜
	for (int i = 0; i < n; i++)
	{
		fw[i][i] = 0;
	}

	for (const auto& edge : edges)
	{
		int s = edge.first;
		const auto& info = edge.second;
		for (const auto& i : info)
		{
			int t = i.first;
			int cost = i.second;
			fw[s][t] = cost;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
			}
		}
	}

	// 특정한 최단 경로 문제
	int answer = limit;

	for (int i = 0; i < n; i++)
	{
		int totalCost = fw[s - 1][i] + fw[i][a - 1] + fw[i][b - 1];
		answer = min(answer, totalCost);
	}

	return answer;
}