#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

int FindParent(vector<int>& pv, int x)
{
	if (pv[x] == x)
		return x;

	return pv[x] = FindParent(pv, pv[x]);
}

bool Union(vector<int>& pv, int a, int b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;

	pv[a] = b;

	return true;
}

struct Edge
{
	int s, t, cost;
};

int FindVal(unordered_map<int, vector<pair<int, int>>>& graphs, int s, int t,int n)
{
	queue<pair<int, int>> q;
	// 현재 위치, 현재까지 가능했던 폭
	q.push({ s,201 });

	vector<int> visited(n, false);

	while (q.empty() == false)
	{
		int nowp = q.front().first;
		int nowsmall = q.front().second;
		q.pop();

		if (nowp == t)
		{
			return nowsmall;
		}

		if (visited[nowp])
			continue;

		visited[nowp] = true;

		if (graphs.find(nowp) == graphs.end())
			continue;

		if (graphs[nowp].size() == 0)
			continue;

		for (pair<int, int>& pii : graphs[nowp])
		{
			q.push({ pii.first, min(pii.second,nowsmall) });
		}
	}

	return -1;
}

int main()
{
	// 일반적인 비용을 구하는것이 아닌,
	// 연결 구간에서 폭을 가능한 높게 맞추는 문제
	// (이전에 본 파이프 쪽 문제와 비슷하긴 하지만 그건 dp)
	// 
	// - 일단 폭이 넓은 것을 기준으로 mst 만들기
	//   (새로운 그래프용?)
	// 
	// 이후, mst 완성후
	// r의 a,b 까지 가는 경로에서 가장 낮은 폭을 반환
	//

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> pv(n);
	for (int i = 0; i < n; i++)
		pv[i] = i;

	vector<Edge> ev;

	for (int i = 0; i < m; i++)
	{
		Edge e;
		cin >> e.s >> e.t >> e.cost;
		e.s--;
		e.t--;
		ev.push_back(e);
	}

	sort(ev.begin(), ev.end(), []
	(const Edge& a, const Edge& b)
		{
			return a.cost > b.cost;
		});

	unordered_map<int, vector<pair<int, int>>> graphs;

	for (const Edge& e : ev)
	{
		if (Union(pv, e.s, e.t))
		{
			graphs[e.s].push_back({ e.t,e.cost });
			graphs[e.t].push_back({ e.s,e.cost });
		}
	}

	vector<pair<int, int>> kv;

	for (int i = 0; i < k; i++)
	{
		int s, t;
		cin >> s >> t;
		s--;
		t--;
		kv.push_back({ s,t });
		
	}

	for (pair<int, int>& pii : kv)
	{
		cout << FindVal(graphs, pii.first, pii.second, n) << '\n';
	}

	return 0;
}