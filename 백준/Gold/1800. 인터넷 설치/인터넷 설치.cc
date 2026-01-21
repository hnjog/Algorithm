#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

struct infos
{
	int now, nowC;
	int remainK;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		if (a.remainK == b.remainK)
			return a.nowC > b.nowC;

		return a.remainK < b.remainK;
	}
};

int GetMaxV(const int n, const int k, unordered_map<int, vector<pii>>& maps)
{
	priority_queue<infos, vector<infos>, Compare> pq;
	pq.push({ 1,0,k });

	vector<vector<int>> visited(n + 1, vector<int>(k + 1, 1e9));

	while (pq.empty() == false)
	{
		int now = pq.top().now;
		int nowC = pq.top().nowC;
		int nowRK = pq.top().remainK;
		pq.pop();

		if (visited[now][nowRK] <= nowC)
			continue;

		visited[now][nowRK] = nowC;

		if (now == n &&
			nowRK == 0)
		{
			return nowC;
		}

		for (pii& p : maps[now])
		{
			if (nowRK > 0)
				pq.push({ p.first,nowC,nowRK - 1 });

			pq.push({ p.first, max(nowC , p.second),nowRK });
		}
	}

	return -1;
}

int main()
{
	// 1 -> n 까지의 최소 길이를 구하는 문제
	// - 도달 불가능시 -1
	// - k개 만큼 '해당 경로 비용을 깎아줌'
	// 
	// 다익스트라의 응용 같기는 함
	// 
	// 추측?
	// 일단 어떤 경로라도 살펴볼 가치가 있을 수 있음
	// 
	// - k 사용 (해당 경로 비용은 포함 x,k가 1이상이여야 가능)
	// - k 사용 안 함(해당 경로 비용 포함, k개수 줄어듦)
	// 
	// k개의 개수를 visit와 함께 다루어야 할듯??
	// 
	// k를 사용 안한 순으로 
	// 비용이 적은 순으로
	// 
	// 음... 지금보니까
	// 연결하는 케이블 중 가장 비싼것만 가격을 받네...??
	//
	//

	int n, p, k;
	cin >> n >> p >> k;

	unordered_map<int, vector<pii>> maps;

	for (int i = 0; i < p; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		maps[a].push_back({ b,c });
		maps[b].push_back({ a,c });
	}

	cout << GetMaxV(n, k, maps);

	return 0;
}