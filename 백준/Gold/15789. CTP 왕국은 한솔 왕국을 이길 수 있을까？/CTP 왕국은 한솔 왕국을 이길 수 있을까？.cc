#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

typedef pair<int, int> pii;

int FindParent(vector<pii>& pv, int x)
{
	if (pv[x].first == x)
		return x;

	return pv[x].first = FindParent(pv, pv[x].first);
}

bool Unions(vector<pii>& pv, int a, int b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;

	pv[a].first = b;
	pv[b].second += pv[a].second;
	pv[a].second = 0;

	return true;
}

int GetValue(vector<pii>& pv, int x)
{
	int p = FindParent(pv, x);
	return pv[p].second;
}

struct Compare
{
	bool operator()(const pii& a, const pii& b)
	{
		return a.second < b.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<pii> pv(n);
	for (int i = 0; i < n; i++)
	{
		pv[i].first = i;
		pv[i].second = 1;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		Unions(pv, a, b);
	}
	
	int c, h, k;
	cin >> c >> h >> k;
	c--;
	h--;

	priority_queue<pii, vector<pii>, Compare> pq;

	int sum = GetValue(pv,c);
	int pc = FindParent(pv, c);
	int ph = FindParent(pv, h);

	unordered_set<int> us;
	for (int i = 0; i < n; i++)
	{
		int pi = FindParent(pv, i);

		if (pi == pc || pi == ph)
			continue;

		if (us.find(pi) == us.end())
		{
			us.insert(pi);
			pq.push({ pi,GetValue(pv,pi) });
		}
	}

	for (int i = 0; i < k; i++)
	{
		if (pq.empty())
			break;

		sum += pq.top().second;
		pq.pop();
	}

	cout << sum;

	return 0;
}