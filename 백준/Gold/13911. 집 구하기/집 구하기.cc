#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef pair<int, int> pii;

struct infos
{
	int now, nowc;
	bool bMac;
};

struct Compare
{
	bool operator()(const infos& a, const infos& b)
	{
		return a.nowc > b.nowc;
	}
};

int getV(const int n,unordered_map<int, vector<pair<int, int>>>& maps, vector<int>& ms,int mx, vector<int>& ss,int sx)
{
	priority_queue<infos, vector<infos>, Compare> pq;

	vector<pii> visited(n + 1, {1e9,1e9});
	unordered_set<int> notHouseS;

	for (int m : ms)
	{
		pq.push({ m,0,true });
		notHouseS.insert(m);
	}

	for (int s : ss)
	{
		pq.push({ s,0,false });
		notHouseS.insert(s);
	}

	while (pq.empty() == false)
	{
		int n = pq.top().now;
		int nc = pq.top().nowc;
		bool bm = pq.top().bMac;
		pq.pop();

		if (bm)
		{
			if (visited[n].first <= nc)
				continue;

			visited[n].first = nc;
		}
		else
		{
			if (visited[n].second <= nc)
				continue;

			visited[n].second = nc;
		}

		for (pii& p : maps[n])
		{
			pq.push({ p.first,nc + p.second,bm });
		}
	}

	int ret = 1e9;

	for (int i = 1; i <= n; i++)
	{
		if (notHouseS.find(i) != notHouseS.end())
			continue;

		if (visited[i].first > mx)
			continue;

		if (visited[i].second > sx)
			continue;

		int s = visited[i].first + visited[i].second;
		if (s < ret)
			ret = s;
	}

	if (ret >= 1e9)
		ret = -1;

	return ret;
}

int main()
{
	int v, e;
	cin >> v >> e;

	unordered_map<int, vector<pair<int, int>>> maps;
	maps.reserve(e);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		maps[a].push_back({ b,c });
		maps[b].push_back({ a,c });
	}

	int m, mx;
	cin >> m >> mx;
	
	vector<int> ms;
	ms.reserve(m);

	for (int i = 0; i < m; i++)
	{
		int t;
		cin >> t;
		ms.push_back(t);
	}

	int s, sx;
	cin >> s >> sx;

	vector<int> ss;
	ss.reserve(s);

	for (int i = 0; i < s; i++)
	{
		int t;
		cin >> t;
		ss.push_back(t);
	}

	cout << getV(v,maps, ms,mx, ss,sx);

	return 0;
}