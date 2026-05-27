#include <string>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& tree, const vector<int>& info, vector<bool>& visited, int sheepCount, int wolfCount, vector<int> next, int& answer)
{
	// next 내부에 있는걸 돌면서?
	if (sheepCount <= wolfCount)
		return;

	answer = max(answer, sheepCount);

	int nSize = next.size();

	for (int i = 0; i < nSize; i++)
	{
		int now = next[i];

		if (visited[now] == true)
			continue;

		visited[now] = true;

		// 복사용
		vector<int> newNext = next;

		// 자기 자신인 i번째 요소를 지움
		newNext.erase(newNext.begin() + i);

		for (int child : tree[now])
		{
			if (visited[child] == false)
			{
				newNext.push_back(child);
			}
		}

		// 양인 경우
		if (info[now] == 0)
		{
			dfs(tree, info, visited, sheepCount + 1, wolfCount, newNext, answer);
		}
		else
		{
			dfs(tree, info, visited, sheepCount, wolfCount + 1, newNext, answer);
		}

		visited[now] = false;
	}
}

int solution(vector<int> info, vector<vector<int>> edges) {
	// dfs 와 백트래킹을 이용하여 풀기
	const int n = info.size();
	vector<vector<int>> tree(n, vector<int>());

	for (const auto& e : edges)
	{
		int begin = e[0];
		int to = e[1];
		tree[begin].push_back(to);
		tree[to].push_back(begin);
	}

	vector<bool> visited(n, false);
	
	// tree의 첫번째 요소부터 시작(루트)
	vector<int> next = tree[0];
	visited[0] = true;

	int answer = 0;
	dfs(tree, info, visited, 1, 0, next, answer);

	return answer;
}