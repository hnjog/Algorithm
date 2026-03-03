#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

typedef pair<int, int> pii;

struct Compare
{
	bool operator()(const pii& a, const pii& b)
	{
		if (a.first == b.first)
			return a.second > b.second;

		return a.first > b.first;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> pv(n, 0);
	for (int i = 0; i < n; i++)
		pv[i] = i;

	priority_queue<pii, vector<pii>, Compare> pq;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		
		pq.push({ a,b });
	}

	int mIdx = 0;

	while (pq.empty() == false)
	{
		int f = pq.top().first;
		int e = pq.top().second;
		pq.pop();

		int i = max(f, mIdx);

		for (; i < e; i++)
		{
			Union(pv,i, i + 1);
		}

		mIdx = e;
	}

	int c = 1;
	int cv = FindParent(pv,0);

	for (int i = 1; i < n; i++)
	{
		if (cv != FindParent(pv,i))
		{
			c++;
			cv = pv[i];
		}
	}

	cout << c;

	return 0;
}