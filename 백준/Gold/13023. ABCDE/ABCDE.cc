#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int n, m;
const int depth = 5;

bool dfs(unordered_map<int, vector<int>>& fmaps, vector<bool>& visited, int now, int count)
{
	if (visited[now])
		return false;

	visited[now] = true;

	if (count == depth)
	{
		return true;
	}

	if (fmaps.find(now) != fmaps.end())
	{
		for (int next : fmaps[now])
		{
			if (dfs(fmaps, visited, next, count + 1))
				return true;
		}
	}

	visited[now] = false;

	return false;
}

int main()
{
	cin >> n >> m;

	unordered_map<int, vector<int>> fmaps;

	for (int i = 0; i < m; i++)
	{
		int s, t;
		cin >> s >> t;
		fmaps[s].push_back(t);
		fmaps[t].push_back(s);
	}

	vector<bool> visited(n + 1);

	for (int i = 0; i < n; i++)
	{
		if (dfs(fmaps, visited, i, 1))
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}