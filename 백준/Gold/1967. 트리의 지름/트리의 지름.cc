#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>

using namespace std;

int n;
int bestResult = 0;

int search(unordered_map<int, vector<pair<int, int>>>& map, int start)
{
	int resultNode = 0;
	queue<pair<int, int>> q;
	q.push({ start,0 });

	vector<bool> visited(n + 1, false);

	while (q.empty() == false)
	{
		int now = q.front().first;
		int nowCost = q.front().second;
		q.pop();

		if (visited[now])
			continue;

		visited[now] = true;

		if (nowCost > bestResult)
		{
			bestResult = nowCost;
			resultNode = now;
		}

		for (pair<int, int>& pii : map[now])
		{
			q.push({ pii.first,pii.second + nowCost });
		}
	}

	return resultNode;
}

int main()
{
	cin >> n;

	unordered_map<int, vector<pair<int, int>>> maps;

	for (int i = 0; i < n - 1; i++)
	{
		int s, e, c;
		cin >> s >> e >> c;

		maps[s].push_back({ e,c });
		maps[e].push_back({ s,c });
	}

	int target = search(maps, 1);
	search(maps, target);

	cout << bestResult;
}