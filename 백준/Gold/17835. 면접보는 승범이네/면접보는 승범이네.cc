#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>

using namespace std;

typedef pair<long, long> pii;

int n, m, k;

struct Compare
{
	bool operator()(pii& a, pii& b)
	{
		return a.second > b.second;
	}
};

vector<long> getV(unordered_map<int, vector<pii>>& maps, vector<int>& ks)
{
	vector<long> visit(n, LONG_MAX);

	priority_queue<pii, vector<pii>, Compare> pq;
	for(int i = 0; i < k;i++)
		pq.push({ ks[i],0 });

	while (pq.empty() == false)
	{
		long now = pq.top().first;
		long nowC = pq.top().second;
		pq.pop();

		if (visit[now] <= nowC)
			continue;

		visit[now] = nowC;

		for (pii& p : maps[now])
		{
			pq.push({ p.first,p.second + nowC });
		}
	}

	return visit;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	unordered_map<int, vector<pii>> maps;
	
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> v >> u >> c;
		u--;
		v--;
		maps[u].push_back({ v,c });
	}

	vector<int> ks(k);

	for (int i = 0; i < k; i++)
	{
		cin >> ks[i];
		ks[i]--;
	}

	vector<long> vV = getV(maps, ks);

	long num = -1;
	long numV = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (vV[i] > numV)
		{
			num = i + 1;
			numV = vV[i];
		}
	}

	cout << num << '\n';
	cout << numV;

	return 0;
}