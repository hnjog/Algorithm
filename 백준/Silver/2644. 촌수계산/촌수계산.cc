#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

int n,startV,endV,listC;

int find(unordered_map<int, vector<int>>& maps)
{
	struct inf
	{
		int now;
		int cost;
	};

	queue<inf> q;
	q.push({ startV,0 });

	vector<bool> visit(n + 1, false);

	while (q.empty() == false)
	{
		int now = q.front().now;
		int nowCost = q.front().cost;
		q.pop();

		if (now == endV)
		{
			return nowCost;
		}

		if (visit[now])
			continue;

		visit[now] = true;

		for (int next : maps[now])
		{
			q.push({ next,nowCost + 1 });
		}
	}

	return -1;
}

int main()
{
	cin >> n;
	cin >> startV >> endV;
	cin >> listC;

	unordered_map<int, vector<int>> maps;

	for (int i = 0; i < listC; i++)
	{
		int n1,n2;
		cin >> n1 >> n2;
		maps[n1].push_back(n2);
		maps[n2].push_back(n1);
	}

	cout << find(maps);
}