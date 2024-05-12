#include <string>
#include <vector>
#include<algorithm>

using namespace std;

void dfs(int start, vector<int>& parents, const vector<vector<int>>& computers)
{
	const auto& startEdges = computers[start];

	for (int i = 0; i < startEdges.size(); i++)
	{
		if (startEdges[i] == 1 && parents[i] != parents[start])
		{
			parents[i] = parents[start];
			dfs(i, parents, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 1;
	// vector<bool? 혹은 int> 로 자기 자신을 처음 '부모'로 인지시키고
	// dfs 등을 돌며 '부모'를 갱신하기
	// 마지막에 서로 다른 부모의 개수를 구하면 될듯?

	vector<int> parents;
	for (int i = 0; i < n; i++)
	{
		// 처음엔 자기자신이 부모
		parents.push_back(i);
	}

	for (int i = 0; i < n; i++)
	{
		dfs(i, parents, computers);
	}

	sort(parents.begin(), parents.end());

	int begin = parents[0];

	for (int i = 1; i < n; i++)
	{
		if (parents[i] != begin)
		{
			answer++;
			begin = parents[i];
		}
	}

	return answer;
}