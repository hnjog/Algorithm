#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

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

struct edge
{
	long s, t, cost;
};

struct Compare
{
	bool operator()(const edge& a, const edge& b)
	{
		return a.cost > b.cost;
	}
};

int main()
{
	/*
		생각해볼점
		결국 0번과 연결이 되어 있는지를 확인하는 문제

		다만,
		결국 저 '단절'을 어떻게 표현하는지가...

		단절이 없다면 해당 인접한 노드들은
		비용 0으로 연결

		1. 초기 비용을 기반으로 edge 생성
		2. pq에 일단 넣기(비용 기반)
		3. 단절되지 않은 녀석들은 0 코스트로 pq에 넣기 -> 이게 고민
			- 단절 되지 않은 녀석들에 대한 시도를 어떻게 파악할 수 있을까?
			- 방법 : pair<int,int> 를 set으로 만든 후, 단절된 녀석을 찾아 제거하기
			  
		4. 연결 시도하기
			(기본적으로 0,0 이 연결됨)
		5. 최종 코스트 출력하기

		로직 자체는 괜찮긴 한데...
		우리에게 주어지는 것은 '단절'된 정보만이 주어짐

	*/

	long n, m, k;
	cin >> n >> m >> k;

	vector<int> pv(n + 1, 0);
	for (int i = 0; i <= n; i++)
	{
		pv[i] = i;
	}

	priority_queue<edge, vector<edge>, Compare> pq;
	unordered_map<long, long> um;

	for (int i = 1; i <= n; i++)
	{
		long t;
		cin >> t;
		
		pq.push({0,i,t});
		if (i != n)
			um[i] = i + 1;
		else
			um[i] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		long a, b;
		cin >> a >> b;

		if (um.find(a) != um.end() &&
			um[a] == b)
		{
			um.erase(a);
		}
	}

	for (auto& p : um)
	{
		pq.push({ p.first,p.second,0 });
	}

	long s = 0;

	// pq 돌면서 체크하기
	while (pq.empty() == false)
	{
		const edge& e = pq.top();
		if (Union(pv, e.s, e.t))
		{
			s += e.cost;
		}
		pq.pop();
	}

	// 공사중이 하나라 이하라면 그냥 돌아갈 수 있음
	if (m <= 1)
		s = 0;

	if (s <= k)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
}