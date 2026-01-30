#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<limits.h>

using namespace std;

typedef pair<long, long> pii;

long getV(pii& a, pii& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
	vector<pii> pv;
	pv.reserve(8);

	pii start;
	cin >> start.second >> start.first;

	pv.push_back(start);

	pii end;
	cin >> end.second >> end.first;

	for (int i = 0; i < 3; i++)
	{
		long y1, x1, y2, x2;
		cin >> x1 >> y1 >> x2 >> y2;

		pv.push_back({ y1,x1 });
		pv.push_back({ y2,x2 });
	}

	pv.push_back(end);

	vector<vector<long>> vm(8, vector<long>(8, LONG_MAX));

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			vm[i][j] = getV(pv[i], pv[j]);
		}
	}

	for (int i = 1; i < 6; i+=2)
	{
		vm[i][i + 1] = min(vm[i][i + 1], (long)10);
		vm[i + 1][i] = min(vm[i + 1][i], (long)10);
	}

	for (int k = 0; k < 8; k++)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				vm[i][j] = min(vm[i][j], vm[i][k] + vm[k][j]);
			}
		}
	}

	cout << vm[0][7];

	return 0;
}