#include<iostream>
#include<map>
#include<vector>
#include<limits.h>

using namespace std;

int dp[1000001];

int main()
{
	int n;
	cin >> n;

	// 만들어진 수, 최소 부모
	map<int, int> m;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	m[0] = 0;
	m[1] = 1;
	m[2] = 1;
	m[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		if (dp[i] == 0)
			dp[i] = INT_MAX;

		dp[i] = min(dp[i - 1] + 1, dp[i]);
		m[i] = i - 1;

		if (i % 2 == 0 &&
			dp[i] > dp[i/2] + 1)
		{
			m[i] = i / 2;
			dp[i] = dp[i / 2] + 1;
		}

		if (i % 3 == 0 &&
			dp[i] > dp[i / 3] + 1)
		{
			m[i] = i / 3;
			dp[i] = dp[i / 3] + 1;
		}
	}

	cout << dp[n] << '\n';

	int nextN = n;

	while (nextN != 1)
	{
		cout << nextN << ' ';
		nextN = m[nextN];
	}
	
	cout << 1;
}