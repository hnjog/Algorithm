#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

int FindP(vector<pii>& pv, int x)
{
	if (pv[x].first == x)
		return x;

	return pv[x].first = FindP(pv, pv[x].first);
}

bool Union(vector<pii>& pv, int a, int b)
{
	a = FindP(pv, a);
	b = FindP(pv, b);

	if (a == b)
		return false;

	if (pv[a].second > pv[b].second)
		pv[a].first = b;
	else
		pv[b].first = a;

	return true;
}

int getV(unordered_map<int, vector<int>>& maps, int start)
{
	int ret = 0;

	queue<pii> nq;
	nq.push({ start,0 });
	set<int> visit;

	while (nq.empty() == false)
	{
		int now = nq.front().first;
		int nowC = nq.front().second;
		nq.pop();

		if (visit.find(now) != visit.end())
			continue;

		visit.insert(now);

		if (nowC > ret)
			ret = nowC;

		for (int n : maps[now])
		{
			nq.push({ n,nowC + 1 });
		}
	}

	return ret;
}

int main()
{
	// 분리집합으로 풀 수 있어 보임 
	// 
	// 여태까지 나온 녀석들의 수를 1씩 늘림
	// 
	// 이후
	// 주어진 간선들을 union 할때
	// 값이 높은 쪽에 붙도록 조정
	// 
	// 이후 set에 결과 담고 그대로 출력
	//

	int n, m;
	cin >> n >> m;



	vector<pii> edges;
	unordered_map<int, vector<int>> maps;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		edges.push_back({ a,b });
		maps[a].push_back(b);
		maps[b].push_back(a);
	}

	vector<pii> pv(n);

	for (int i = 0; i < n; i++)
	{
		pv[i].first = i;
		pv[i].second = getV(maps, i);
	}

	set<int> ret;

	for (pii& p : edges)
	{
		Union(pv, p.first, p.second);
	}

	for (int i = 0; i < n; i++)
	{
		ret.insert(FindP(pv, pv[i].first) + 1);
	}

	cout << ret.size() << '\n';

	for (int r : ret)
	{
		cout << r << '\n';
	}

	return 0;
}