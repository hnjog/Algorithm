#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Logs
{
	int x1, x2, y;
	int idx;
	int parent;
};

int FindParent(vector<Logs>& pv, Logs& l)
{
	int lp = l.parent;
	if (pv[lp].parent == lp)
		return lp;

	return pv[lp].parent = FindParent(pv, pv[lp]);
}

bool UnionP(vector<Logs>& pv, Logs& a, Logs& b)
{
	int ap = FindParent(pv, a);
	int bp = FindParent(pv, b);

	if (ap == bp)
		return false;

	Logs& al = pv[ap];
	Logs& bl = pv[bp];

	if (al.x2 < bl.x1 ||
		al.x1 > bl.x2)
		return false;

	al.parent = bl.parent;
	bl.x1 = min(bl.x1, al.x1);
	bl.x2 = max(bl.x2, al.x2);

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<Logs> pv(n);

	for (int i = 0; i < n; i++)
	{
		cin >> pv[i].x1 >> pv[i].x2 >> pv[i].y;
		pv[i].idx = i;
	}

	sort(pv.begin(), pv.end(), []
	(const Logs& a, const Logs& b)
		{
			return a.x1 < b.x1;
		});

	for (int i = 0; i < n; i++)
	{
		pv[i].parent = i;
	}

	for (int i = 0; i < n - 1; i++)
	{
		UnionP(pv, pv[i], pv[i + 1]);
	}

	for (int i = 0; i < n; i++)
	{
		int pi = FindParent(pv, pv[i]);
		if (pi == i)
		{
			pv[i].parent = pv[i].idx;
		}
		else
		{
			pv[i].parent = pv[pi].idx;
		}
	}

	sort(pv.begin(), pv.end(), []
	(const Logs& a, const Logs& b)
		{
			return a.idx < b.idx;
		});

	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;

		if (FindParent(pv, pv[a]) == FindParent(pv, pv[b]))
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}

	return 0;
}