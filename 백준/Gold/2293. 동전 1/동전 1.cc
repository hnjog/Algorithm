#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	vector<int> dp(k + 1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	// 0을 만들게 되는 경우 + 1
	dp[0] = 1;

	// 반복문을 도는 주체가 coin 일것
	// 각 '수'마다 돌 경우 (0~k) - 코인들의 결과가 섞임
	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			dp[j] += dp[j - coins[i]];
		}
	}

	cout << dp[k];

	return 0;
}