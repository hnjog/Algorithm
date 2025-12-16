#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long FindParent(vector<pair<long long, long long>>& pv, long long x)
{
	if (pv[x].first == x)
		return x;

	return pv[x].first = FindParent(pv, pv[x].first);
}

bool Union(vector<pair<long long, long long>>& pv, long long a, long long b)
{
	a = FindParent(pv, a);
	b = FindParent(pv, b);

	if (a == b)
		return false;

	pv[b].second += pv[a].second;
	pv[a].second = 0;
	pv[a].first = b;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;

	vector<pair<long long, long long>> pv(n);

	for (long long i = 0; i < n; i++)
	{
		long long s;
		cin >> s;
		pv[i] = { i ,s };
	}

	for (long long i = 0; i < m; i++)
	{
		long long v1,v2;
		cin >> v1 >> v2;
		v1--;
		v2--;

		Union(pv, v1,v2);

		long long p = FindParent(pv, v1);
		
		cout << pv[p].second << '\n';
	}

	return 0;
}