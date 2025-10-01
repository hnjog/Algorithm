#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
#include<memory.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int maps[3] = { 0, };
	int maxDp[2][3] = { 0, };
	int minDp[2][3];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			minDp[i][j] = INT_MAX / 2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> maps[j];

			if (i == 0)
			{
				maxDp[i][j] = maps[j];
				minDp[i][j] = maps[j];
			}
		}

		if (i > 0)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j > 0)
				{
					maxDp[1][j - 1] = max(maxDp[1][j - 1], maxDp[0][j] + maps[j - 1]);
					minDp[1][j - 1] = min(minDp[1][j - 1], minDp[0][j] + maps[j - 1]);
				}

				maxDp[1][j] = max(maxDp[1][j], maxDp[0][j] + maps[j]);
				minDp[1][j] = min(minDp[1][j], minDp[0][j] + maps[j]);

				if (j < 2)
				{
					maxDp[1][j + 1] = max(maxDp[1][j + 1], maxDp[0][j] + maps[j + 1]);
					minDp[1][j + 1] = min(minDp[1][j + 1], minDp[0][j] + maps[j + 1]);
				}
			}

			for (int j = 0; j < 3; j++)
			{
				maxDp[0][j] = maxDp[1][j];
				maxDp[1][j] = 0;

				minDp[0][j] = minDp[1][j];
				minDp[1][j] = INT_MAX / 2;
			}
		}
		
	}

	int maxV = maxDp[0][0];
	int minV = minDp[0][0];

	for (int i = 1; i < 3; i++)
	{
		if (maxDp[0][i] > maxV)
			maxV = maxDp[0][i];

		if (minDp[0][i] < minV)
			minV = minDp[0][i];
	}

	cout << maxV << " " << minV;

	return 0;
}