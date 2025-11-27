#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> caf(n);
	for (int i = 0; i < n; i++)
	{
		cin >> caf[i];
	}

	vector<int> dp(k + 1, -1);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = k; j >= caf[i]; j--)
		{
			if (dp[j - caf[i]] == -1)
				continue;

			if (dp[j] == -1)
				dp[j] = dp[j - caf[i]] + 1;
			else
				dp[j] = min(dp[j], dp[j - caf[i]] + 1);
		}
	}

	cout << dp[k];

	return 0;
}