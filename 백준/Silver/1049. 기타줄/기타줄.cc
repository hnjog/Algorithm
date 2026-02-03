#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int bestSetV = 1001, bestOneV = 1001;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < bestSetV)
			bestSetV = a;

		if (b < bestOneV)
			bestOneV = b;
	}

	if (bestSetV > bestOneV * 6)
		bestSetV = bestOneV * 6;

	int nowC = 0;
	int v = 0;

	while (nowC < n)
	{
		if (nowC <= n - 6)
		{
			nowC += 6;
			v += bestSetV;
		}
		else
		{
			int c = n - nowC;
			if (bestOneV * c < bestSetV)
			{
				v += bestOneV * c;
			}
			else
			{
				v += bestSetV;
			}

			nowC = n;
		}
	}

	cout << v;

	return 0;
}