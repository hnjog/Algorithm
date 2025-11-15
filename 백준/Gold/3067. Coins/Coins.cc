#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t > 0)
	{
		int n;
		cin >> n;

		vector<int> coins(n);
		for (int i = 0; i < n; i++)
			cin >> coins[i];

		int m;
		cin >> m;

		vector<int> dp(m + 1);

		for (int i = 0; i < n; i++)
		{
			dp[coins[i]] += 1;

			for (int j = coins[i]; j <= m; j++)
			{
				dp[j] += dp[j - coins[i]];
			}
		}

		cout << dp[m] << '\n';

		t--;
	}

	return 0;
}