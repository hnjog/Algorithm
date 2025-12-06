#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long sum = 0;
	for (long long i = 1; i <= n; i++)
		sum += i;

	if (sum % 2 == 1)
	{
		cout << 0;
		return 0;
	}

	// 합이 같아야 함
	// 그렇기에 최종 목표값이 sum / 2
	long long target = sum / 2;

	vector<long long> dp(target + 1, -1);
	dp[0] = 1;

	for (long long i = 1; i <= n; i++)
	{
		for (long long j = target; j >= i;j--)
		{
			if (dp[j - i] == -1)
				continue;

			if (dp[j] == -1)
				dp[j] = dp[j - i];
			else
				dp[j] += dp[j - i];
		}
	}

	cout << dp[target] / 2;

	return 0;
}