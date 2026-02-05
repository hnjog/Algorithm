#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

double GetDis(int y1, int x1, int y2, int x2)
{
	if (x1 == x2)
	{
		return abs(y1 - y2);
	}
	
	if (y1 == y2)
	{
		return abs(x1 - x2);
	}

	return sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
}

void dfs(vector<pair<int, int>>& pv, vector<bool>& visit, double& mv, double v, int c, int ny, int nx)
{
	if (c >= 3)
	{
		if (v < mv)
			mv = v;

		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (visit[i])
			continue;

		visit[i] = true;
		double nowv = GetDis(ny, nx, pv[i].first, pv[i].second);
		dfs(pv, visit, mv, v + nowv, c + 1, pv[i].first, pv[i].second);
		visit[i] = false;
	}
}

int main()
{
	double val = 1e9;

	int ny, nx;
	cin >> nx >> ny;

	vector<pair<int, int>> pv;
	vector<bool> visited(3, false);

	for (int i = 0; i < 3; i++)
	{
		int tx, ty;
		cin >> tx >> ty;

		pv.push_back({ ty,tx });
	}

	dfs(pv, visited, val, 0, 0, ny, nx);

	cout << (int)val;

	return 0;
}