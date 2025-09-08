#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<limits.h>

using namespace std;

struct node
{
	int idx; // 노드 번호
	int value; // 비용
	int degree; // 차수
	vector<int> next;
};

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(const pii& a, const pii& b)
	{
		return a.second > b.second;
	}
};

int func(vector<int>& starts, int to, unordered_map<int, node>& nodemap)
{
	// 차수가 0인 녀석을 queue에 넣음
	priority_queue<pii, vector<pii>, Compare> pq;
	unordered_map<int, int> dp;

	for (int start : starts)
	{
		if (start == to)
			return nodemap[start].value;

		pq.push({ start, nodemap[start].value });
	}

	while (pq.empty() == false)
	{
		int now = pq.top().first;
		int nowTime = pq.top().second;
		pq.pop();

		if (now == to)
		{
			return nowTime;
		}

		// 그냥 다음 녀석과 다음 시간을 넣어주면 됨
		// 어차피 시간이 작은 녀석이 먼저 q 앞에 오고
		// 차수가 0인 녀석만 넣어줄거니 자동으로 뒷 시간에 맞춰짐
		for (int next : nodemap[now].next)
		{
			nodemap[next].degree--;
			if (nodemap[next].degree <= 0)
			{
				pq.push({ next,nodemap[next].value + nowTime });
			}
		}
	}

	return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		t--;

		int n, k;
		cin >> n >> k;
		unordered_map<int, node> nodemap;
		for (int i = 1; i <= n; i++)
		{
			nodemap[i].idx = i;
			cin >> nodemap[i].value;
		}

		// '거꾸로' 등록하고 목적지에서 시작할 예정
		for (int i = 0; i < k; i++)
		{
			int start, to;
			cin >> start >> to;
			nodemap[start].next.push_back(to);
			nodemap[to].degree++;
		}

		int to;
		cin >> to;

		vector<int> starts;
		for (auto& p : nodemap)
		{
			if (p.second.degree == 0)
			{
				starts.push_back(p.first);
			}
		}

		cout << func(starts, to, nodemap) << '\n';
	}

	return 0;
}