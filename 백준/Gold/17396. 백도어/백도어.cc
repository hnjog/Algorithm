#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<limits.h>

using namespace std;

struct Compare
{
	bool operator()(const pair<long,long>& a, const pair<long,long>& b)
	{
		return a.second > b.second;
	}
};

long getv(unordered_map<long, vector<pair<long,long>>>& maps,long n)
{
	vector<long> visited(n, LONG_MAX);

	priority_queue<pair<long,long>, vector<pair<long,long>>, Compare> pq;
	pq.push({ 0,0 });

	while (pq.empty() == false)
	{
		long now = pq.top().first;
		long nowC = pq.top().second;
		pq.pop();

		if (visited[now] <= nowC)
			continue;

		visited[now] = nowC;

		if (now == n - 1)
			return nowC;

		if (maps.find(now) == maps.end())
			continue;

		for (pair<long,long>& p : maps[now])
		{
			long next = p.first;
			long nextc = p.second + nowC;

			if (visited[next] <= nextc)
				continue;

			pq.push({next,nextc});
		}
	}

	return -1;
}

int main()
{
	long n, m;
	cin >> n >> m;

	vector<bool> hiddens(n);

	for (long i = 0; i < n; i++)
	{
		long t;
		cin >> t;
		if (t == 0)
		{
			hiddens[i] = true;
		}
		else
		{
			hiddens[i] = false;
		}
	}

	unordered_map<long, vector<pair<long,long>>> maps;

	for (long i = 0; i < m; i++)
	{
		long a, b, c;
		cin >> a >> b >> c;

		if(hiddens[b] == true ||
			b == n-1)
			maps[a].push_back({ b,c });

		if (hiddens[a] == true ||
			a == n - 1)
			maps[b].push_back({ a,c });
	}

	cout << getv(maps, n);

	return 0;
}