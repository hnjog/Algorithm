#include<iostream>
#include<set>
#include<unordered_map>
#include<queue>

using namespace std;

void bfs(unordered_map<int, set<int>>& maps, unordered_map<int, int>& v, int now)
{
	queue<int> q;
	int step = 1;
	q.push(now);

	while (q.empty() == false)
	{
		int nowPos = q.front();
		q.pop();

		if (v.find(nowPos) != v.end())
			continue;

		v[nowPos] = step;
		step++;

		for (int s : maps[nowPos])
		{
			q.push(s);
		}
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

	bfs(maps, v, start);

	for (int i = 1; i <= n; i++)
	{
		cout << v[i] << "\n";
	}
}