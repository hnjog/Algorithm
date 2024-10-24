#include<iostream>
#include<set>
#include<unordered_map>
#include<algorithm>

using namespace std;

void dfs(unordered_map<int, set<int>>& maps, unordered_map<int, int>& v, int& step, int now)
{
	if (v.find(now) != v.end())
		return;

	v[now] = step;
	step++;

	if (maps.find(now) == maps.end())
		return;

	for (int next : maps[now])
	{
		dfs(maps, v, step, next);
	}
}

int main()
{
	int n, m;
	int start;
	cin >> n >> m >> start;

	unordered_map<int, set<int>> maps;
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		if (maps.find(start) == maps.end())
			maps[start] = set<int>();

		maps[start].insert(end);

		if (maps.find(end) == maps.end())
			maps[end] = set<int>();

		maps[end].insert(start);
	}

	unordered_map<int, int> v;

	int step = 1;
	dfs(maps, v, step, start);

	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << "\n";
	}
}