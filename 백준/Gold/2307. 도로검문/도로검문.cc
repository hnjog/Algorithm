#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

struct infos
{
	int now;
	int nowc;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		return a.nowc > b.nowc;
	}
};

vector<pii> getvv(const int n, unordered_map<int, unordered_map<int, int>>& maps)
{
	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ 1,0 });

	vector<pii> ret(n + 1, {1e9,1e9});
	ret[1].first = 1;
	ret[1].second = 0;

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		int nowc = pq.top().nowc;
		pq.pop();

		if (now == n)
		{
			break;
		}

		for (auto& p : maps[now])
		{
			int ne = p.first;
			int nec = p.second;

			if (ret[ne].second <= nowc + nec)
				continue;

			ret[ne].first = now;
			ret[ne].second = nowc + nec;
			pq.push({ ne,nowc + nec });
		}
	}

	return ret;
}

int GetV(const int n, unordered_map<int, unordered_map<int, int>>& maps, pii banned)
{
	priority_queue<infos, vector<infos>, Compare> pq;
	
	pq.push({ 1,0 });

	vector<int> visited(n + 1, 1e9);

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		int nowc = pq.top().nowc;
		pq.pop();

		if (visited[now] <= nowc)
			continue;

		visited[now] = nowc;

		if (now == n)
		{
			return nowc;
		}

		for (auto& p : maps[now])
		{
			int ne = p.first;
			int nec = p.second;

			if ((banned.first == ne && banned.second == now) ||
				(banned.first == now && banned.second == ne))
				continue;

			pq.push({ ne,nowc + nec });
		}
	}

	return -1;
}

int GetFV(const int n, const int m, unordered_map<int, unordered_map<int, int>>& maps)
{
	// 1. 일반 pq로 경로 와 최단거리 구하기
	vector<pii> load = getvv(n, maps);
	int mv = load[n].second;

	// 2. 금지 경로 저장
	vector<pii> banLoad;
	banLoad.reserve(m);

	int idx = n;
	while (load[idx].first != idx)
	{
		banLoad.push_back({ idx,load[idx].first });
		idx = load[idx].first;
	}

	// 3. 설정된 금지 경로들을 바탕으로 다시 시작점(1)에서부터
	// pq 돌리기

	int ret = 0;

	for (pii& p : banLoad)
	{
		int t = GetV(n, maps, p);
		if (t == -1)
			return -1;

		ret = max(ret, t - mv);
	}

	return ret;
}

int main()
{
	/*
		다익스트라
		- 결국 현재 시점에서 '이동할 모든 경로' 중에서
		  가장 비용이 작은 녀석을 선택
			(실제로는 조건마다 다르지만)
		- 가능성들이 pq에 들어있음
		- 조건 판별에 대하여

		문제에서 원하는 것은
		'특정한 도로'하나를 막아
		목적지에 도착하는 것을 막거나 최대한 지연

		지연효과가 없으면 0 출력
		무한대라면 -1출력

		단순히 가장 싼 비용을 막는 것이 아니긴 함

		1. 다익스트라를 돌리고 
		   그 최단 경로를 찾기
		   ex) 6 -> 3 -> 2 -> 1
		2. 여기서 하나씩 edge를 막고,
		   다시 다익스트라를 돌려
		   가장 높은 비용을 구하기??
    
		일단 역추적을 위해
		pair<int,int>로 이전 방문지 + 현재 비용 을 기록

		이후 pair<int,int> 배열을 ret하거나 바로 다음 로직

		- 목적지를 하나씩 체크(별도의 구조체?)하며
		  다익스트라를 새로 돌림
		   이 때 기존 최소비용과, 새로운 경로의 최소비용을 비교하여
			지연효과를 알 수 있음


		생각해볼 점
		- 일단 하나하나씩 오기에
		  6->3 경로가 다른걸 경유한다 
		  같은 건 아닐거임
		  -> 그랬다면 그 경로에서 6으로 오는 것이 찍히거나
			   3의 다음이 그 경로거나...

		- 자료구조를 어떻게??
		  6->3 경로를 빠르게 찾아와야 함
		  unordered_map<int,unordered_map<int,int>> -> 이거 가능한가...??
		  그냥 map으로 해야할 수 있음


	*/

	int n, m;
	cin >> n >> m;

	unordered_map<int, unordered_map<int, int>> maps;
	maps.reserve(n);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		maps[a][b] = c;
		maps[b][a] = c;
	}

	vector<pii> outs;
	outs.reserve(n + 1);

	cout <<  GetFV(n,m, maps);


	return 0;
}