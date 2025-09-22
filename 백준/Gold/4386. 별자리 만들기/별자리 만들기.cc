#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>
#include <math.h>

using namespace std;

struct starInfo
{
	double y, x;
};

struct starEdgeInfo
{
	int s1, s2;
	double distance;
};

double GetDistance(starInfo& a, starInfo& b)
{
	return sqrt((a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x));
}

int FindParents(vector<int>& pv, int x)
{
	if (pv[x] == x)
		return x;

	return pv[x] = FindParents(pv, pv[x]);
}

bool Union(vector<int>& pv, int a, int b)
{
	a = FindParents(pv, a);
	b = FindParents(pv, b);

	if (a == b)
		return false;

	pv[a] = b;
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<starInfo> infoVec(n);
	vector<int> parents(n);
	for (int i = 0; i < n; i++)
	{
		cin >> infoVec[i].x;
		cin >> infoVec[i].y;

		parents[i] = i;
	}

	vector<starEdgeInfo> edgeInfo;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double dis = GetDistance(infoVec[i], infoVec[j]);
			edgeInfo.push_back({ i,j,dis });
		}
	}

	sort(edgeInfo.begin(), edgeInfo.end(), []
	(const starEdgeInfo& a, const starEdgeInfo& b)
		{
			return a.distance < b.distance;
		});

	double answer = 0;

	for (const starEdgeInfo& e : edgeInfo)
	{
		if (Union(parents, e.s1, e.s2))
		{
			answer += e.distance;
		}
	}

	cout << fixed << setprecision(2) << answer;

	return 0;
}