#include<iostream>
#include<vector>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

int n;

int bestValue(const vector<vector<int>>& maps, vector<vector<int>>& dp,int nowY,int nowX)
{
	if (dp[nowY][nowX] >= 0)
		return dp[nowY][nowX];

    int best = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = nowY + dirY[i];
		int nx = nowX + dirX[i];

		if (ny < 0 || ny >= n ||
			nx < 0 || nx >= n)
			continue;

		if (maps[ny][nx] <= maps[nowY][nowX])
			continue;

		int t = bestValue(maps, dp, ny, nx) + 1;

		if (t > best)
			best = t;
	}

	return dp[nowY][nowX] = best;
}

int main()
{
	cin >> n;
	vector<vector<int>> maps(n, vector<int>(n, 0));
	vector<vector<int>> dp(n, vector<int>(n, -1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> maps[i][j];

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int v = bestValue(maps, dp, i, j);
			if (v > ans)
				ans = v;
		}
	}

	cout << ans + 1;

	return 0;
}