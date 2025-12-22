#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(const pii& a, const pii& b)
	{
		return a.second > b.second;
	}
};

pii VirusWork(unordered_map<int, vector<pair<int, int>>>& um,int n, int c)
{
	pii ret;

	int count = 0;
	int maxTime = 0;

	vector<int> visited(n + 1, -1);

	priority_queue<pii, vector<pii>, Compare> pq;

	pq.push({ c,0 });

	while (pq.empty() == false)
	{
		int now = pq.top().first;
		int nowC = pq.top().second;
		pq.pop();

		if (visited[now] >= 0)
			continue;

		visited[now] = nowC;
		count++;
		if (nowC > maxTime)
			maxTime = nowC;

		for (pii& p : um[now])
		{
			pq.push({ p.first,p.second + nowC });
		}
	}

	ret.first = count;
	ret.second = maxTime;
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t > 0)
	{
		t--;

		int n, d, c;
		cin >> n >> d >> c;

		unordered_map<int, vector<pii>> um;

		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			um[b].push_back({ a,s });
		}

		pii ret = VirusWork(um,n, c);

		cout << ret.first << ' ' << ret.second << '\n';
	}

	return 0;
}