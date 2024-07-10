#include <vector>
#include<unordered_map>
#include<math.h>

using namespace std;

void dfs(unordered_map<int, vector<int>>& m, const vector<int>& a, vector<long long>& sum, int start,int parent, vector<bool>& visited,long long& answer)
{
	visited[start] = true;

	for (int road : m[start])
	{
		if (visited[road])
			continue;

		dfs(m, a, sum, road,start,visited, answer);
	}

	sum[parent] += sum[start];
	answer += abs(sum[start]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
	unordered_map<int, vector<int>> m;
	for (const auto& edge : edges)
	{
		int s = edge[0];
		int t = edge[1];
		if (s > t)
			swap(s, t);

		if (m.find(s) == m.end())
			m[s] = vector<int>();
		m[s].push_back(t);
		if (m.find(t) == m.end())
			m[t] = vector<int>();
		m[t].push_back(s);
	}

	vector<long long> sum(a.size(),0);
	for (int i = 0; i < a.size(); i++)
		sum[i] = a[i];

	long long answer = 0;
	vector<bool> visited(a.size(), false);

	dfs(m, a, sum, answer, 0,visited, answer);

	if (sum[0] != 0)
		return -1;

	return answer;
}