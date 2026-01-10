#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(pii& a, pii& b)
	{
		return a.second > b.second;
	}
};

int getV(unordered_map<int, vector<pii>>& maps, int v, int start, int target)
{
	priority_queue<pii, vector<pii>, Compare> pq;
	pq.push({ start,0 });
	
	vector<int> visited(v + 1, INT_MAX);

	while (pq.empty() == false)
	{
		int now = pq.top().first;
		int nowC = pq.top().second;
		pq.pop();

		if (visited[now] <= nowC)
			continue;

		visited[now] = nowC;

		if (now == target)
			return nowC;

		for (pii& p : maps[now])
		{
			pq.push({ p.first,p.second + nowC });
		}
	}

	return -1;
}

int main()
{
	int v, e, p;
	cin >> v >> e >> p;

	unordered_map<int, vector<pii>> maps;
	maps.reserve(v);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		maps[a].push_back({ b,c });
		maps[b].push_back({ a,c });
	}

	// 1 -> v 로 가는 최소 비용과
	// 1 -> p , p -> v 로 가는 최소 비용의 합을 비교
	// 두 값이 같으면 구할 수 있음
	//

	int v1 = getV(maps, v, 1, v);
	int v2 = getV(maps, v, 1, p) + getV(maps, v, p, v);

	if (v2 <= v1)
	{
		cout << "SAVE HIM";
	}
	else
	{
		cout << "GOOD BYE";
	}

	return 0;
}