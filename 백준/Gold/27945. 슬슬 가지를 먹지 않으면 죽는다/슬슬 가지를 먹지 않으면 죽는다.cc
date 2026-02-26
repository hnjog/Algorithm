#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

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

struct edge
{
	int s, t, day;
};

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> pv(n);
	for (int i = 0; i < n; i++)
		pv[i] = i;

	vector<edge> v;
	v.reserve(m);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		v.push_back({ a,b,c });
	}

	sort(v.begin(), v.end(), []
	(const edge& a, const edge& b)
		{
			return a.day < b.day;
		});

	unordered_set<int> us;
	us.reserve(n);

	for (edge& e : v)
	{
		if (Union(pv, e.s, e.t))
		{
			us.insert(e.day);
		}
	}

	int d = 1;

	while (d <= n)
	{
		if (us.find(d) == us.end())
		{
			break;
		}
		d++;
	}

	cout << d;

	return 0;
}