#include<iostream>
#include<memory.h>

using namespace std;

int dp[501][501];
int map[501][501];

int m, n;

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0,1,0,-1 };

int recur(int nowY, int nowX)
{
	if (nowY == 0 && nowX == 0)
		return 1;

	if (dp[nowY][nowX] != -1)
		return dp[nowY][nowX];

	dp[nowY][nowX] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextY = nowY + dirY[i];
		int nextX = nowX + dirX[i];

		if (nextY < 0 || nextX < 0 ||
			nextY > m || nextX > n)
			continue;

		int nowV = map[nowY][nowX];
		int nextV = map[nextY][nextX];
		if (nowV >= nextV)
			continue;

		dp[nowY][nowX] += recur(nextY, nextX);
	}


	return dp[nowY][nowX];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> m >> n;
	m--;
	n--;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			int t;
			cin >> t;
			map[i][j] = t;
		}
	}

	cout << recur(m, n);
}