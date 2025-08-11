#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		int n;
		cin >> n;
		
		vector<long long> r1(n), r2(n);
		for (int i = 0; i < n; i++)
		{
			cin >> r1[i];
		}

		for (int i = 0; i < n; i++)
		{
			cin >> r2[i];
		}

		vector<vector<int>> dp(3,vector<int>(n+1));
		
		dp[0][0] = r1[0];
		dp[1][0] = r2[0];
		dp[2][0] = 0;

		for (int i = 1; i < n; i++)
		{
			dp[0][i] = r1[i] + max(dp[1][i-1], dp[2][i-1]);
			dp[1][i] = r2[i] + max(dp[0][i-1], dp[2][i-1]);
			int v = max(dp[0][i - 1], dp[1][i - 1]);
			dp[2][i] = max(v, dp[2][i]);
		}

		cout <<max( max(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]) << '\n';

		t--;
	}

	return 0;
}