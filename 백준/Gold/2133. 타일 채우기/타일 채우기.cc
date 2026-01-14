#include<iostream>
#include<vector>

using namespace std;

int dp[31];

int main()
{
	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	for (int i = 4; i <= n; i++)
	{
		if (i % 2 == 1)
			continue;

		dp[i] = 3 * dp[i - 2];

		for (int j = i - 4; j >= 0; j -= 2)
		{
			dp[i] += 2 * dp[j];
		}
	}

	cout << dp[n];
}