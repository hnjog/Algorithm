#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += i;

	if (sum % 2 == 1)
	{
		cout << 0;
		return 0;
	}

	// 합이 같아야 함
	// 그렇기에 최종 목표값이 sum / 2
	int target = sum / 2;

	// dp 정의
	// 
	// - dp[i] ? 
	//   : i값을 만들기 위한 경우의 수?
	//
	// 상태 전이
	// - dp[i + n[i]] += dp[i]
	// 
	//

	vector<int> dp(target + 1, -1);
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = target; j >= i;j--)
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