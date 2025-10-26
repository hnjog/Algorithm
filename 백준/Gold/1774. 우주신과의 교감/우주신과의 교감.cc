#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include <iomanip>

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

struct Star
{
	int y, x;
};

struct Edge
{
	int sIdx;
	int tIdx;
	long double cost;
};

long double GetDis(Star& a, Star& b)
{
	return sqrt(double(a.y - b.y) * (a.y - b.y) + double(a.x - b.x) * (a.x - b.x));
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << fixed << setprecision(2);

	vector<int> pv(n);
	for (int i = 0; i < n; i++)
		pv[i] = i;

	vector<Star> starV(n);

	for (int i = 0; i < n; i++)
	{
		cin >> starV[i].x >> starV[i].y;
	}

	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		Union(pv, t1, t2);
	}

	vector<Edge> ev;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			ev.push_back({ i,j,GetDis(starV[i],starV[j]) });
		}
	}

	sort(ev.begin(), ev.end(), [](const auto& a, const auto& b) {return a.cost < b.cost; });

	long double ans = 0.0;

	for (const auto& e : ev)
	{
		if (Union(pv,e.sIdx, e.tIdx))
		{
			ans += e.cost;
		}
	}

	cout << ans;

	return 0;
}