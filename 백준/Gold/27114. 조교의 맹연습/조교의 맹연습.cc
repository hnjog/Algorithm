#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getdir(int dir, int order)
{
	dir += order;

	if (dir < 0)
		dir = 4 + dir;
	if (dir > 3)
		dir -= 4;

	return dir;
}

int main()
{
	vector<int> weights(3);
	for (int i = 0; i < 3; i++)
		cin >> weights[i];

	int dir[3] = { 1,-1,2 };

	int k;
	cin >> k;

	vector<vector<int>> dp(k + 1, vector<int>(4, -1));
	dp[0][0] = 0;

	for (int i = 0; i < 3; i++)
	{
		int noww = weights[i];
		int nowOrder = dir[i];

		for (int j = 0; j <= k;j++)
		{
			if (j + noww > k)
				break;

			for (int dir = 0; dir <= 3; dir++)
			{
				if (dp[j][dir] == -1)
					continue;

				int nextDir = getdir(dir, nowOrder);

				if (dp[j + noww][nextDir] == -1)
					dp[j + noww][nextDir] = dp[j][dir] + 1;
				else
					dp[j + noww][nextDir] = min(dp[j][dir] + 1, dp[j + noww][nextDir]);
			}
		}
	}

	cout << dp[k][0];

	return 0;
}