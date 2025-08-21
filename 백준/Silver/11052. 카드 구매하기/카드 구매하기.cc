#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> cards(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> cards[i];

	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = cards[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i] = cards[i];

		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[n];

	return 0;
}