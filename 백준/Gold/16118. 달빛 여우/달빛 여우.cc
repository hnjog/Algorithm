#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>

using namespace std;

typedef pair<int, int> pii;

struct infos
{
	int now;
	long double nowCost;
	bool doubleTime = false;
};

struct Compare
{
	bool operator()(infos& a, infos& b)
	{
		return a.nowCost > b.nowCost;
	}
};

void GetFoxV(unordered_map<int, vector<pii>>& maps, vector<long double>& foxVec)
{
	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ 0,0,false });
	
	while (pq.empty() == false)
	{
		int now = pq.top().now;
		long double nowC = pq.top().nowCost;
		pq.pop();

		if (foxVec[now] <= nowC)
			continue;

		foxVec[now] = nowC;

		for (const pii& p : maps[now])
		{
			pq.push({ p.first,p.second + nowC,false });
		}
	}
}

void GetWolfV(unordered_map<int, vector<pii>>& maps, vector<long double>& wolfVec)
{
	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ 0,0,false });

	int n = wolfVec.size();

	vector<long double> av(n, INT_MAX);
	vector<long double> bv(n, INT_MAX);

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		long double nowC = pq.top().nowCost;
		bool bDouble = pq.top().doubleTime;
		pq.pop();

		if (bDouble)
		{
			if (av[now] <= nowC)
				continue;

			av[now] = nowC;
		}
		else
		{
			if (bv[now] <= nowC)
				continue;

			bv[now] = nowC;
		}

		for (const pii& p : maps[now])
		{
			if (bDouble)
			{
				pq.push({ p.first,(p.second) * 2 + nowC,false });
			}
			else
			{
				pq.push({ p.first,(p.second) / 2.0 + nowC,true });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (av[i] < bv[i])
			wolfVec[i] = av[i];
		else
			wolfVec[i] = bv[i];
	}

}

int main()
{
	/*
		여우 : 일반적인 1번에서 시작하는 다익스트라
		늑대 : 변형적인 1번에서 시작하는 다익스트라

		여우는 일반 방식으로
		1번에서 나머지 값들을 구하면 됨
		
		늑대는 특이한 방식 존재
		홀수번째 시도에선 비용 절반
		짝수번째 시도에선 비용 2 배

		그렇기에, 짝수,홀수 도착 시점을 따로 보관하고
		최종 결과물에는 작은값만 담는 방식
	*/

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	unordered_map<int, vector<pii>> maps;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		a--;
		b--;
		maps[a].push_back({ b,c });
		maps[b].push_back({ a,c });
	}

	vector<long double> foxValues(n, INT_MAX);
	vector<long double> wolfValues(n, INT_MAX);

	GetFoxV(maps, foxValues);
	GetWolfV(maps, wolfValues);

	int ret = 0;

	for (int i = 1; i < n; i++)
	{
		if (foxValues[i] < wolfValues[i])
			ret++;
	}

	cout << ret;

	return 0;
}