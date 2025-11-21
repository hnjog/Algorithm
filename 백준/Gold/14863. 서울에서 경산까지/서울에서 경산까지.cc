#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<pair<long, long>> walk, cycle;

	for (int i = 0; i < n; i++)
	{
		long w1, w2, c1, c2;
		cin >> w1 >> w2 >> c1 >> c2;
		walk.push_back({ w1,w2 });
		cycle.push_back({ c1,c2 });
	}

	vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++)
	{
		long walkCost = walk[i - 1].first;
		long walkValue = walk[i - 1].second;
		long cycleCost = cycle[i - 1].first;
		long cycleValue = cycle[i - 1].second;

		for (int j = 0; j <= k; j++)
		{
			long long best = -1;

			if (j >= walkCost &&
				dp[i - 1][j - walkCost] != -1)
			{
				best = max(best, dp[i - 1][j - walkCost] + walkValue);
			}

			if (j >= cycleCost &&
				dp[i - 1][j - cycleCost] != -1)
			{
				best = max(best, dp[i - 1][j - cycleCost] + cycleValue);
			}

			dp[i][j] = best;
		}
	}

	long long ans = 0;
	for (int i = 0; i <= k; i++)
	{
		ans = max(ans, dp[n][i]);
	}

	cout << ans;

	return 0;
}