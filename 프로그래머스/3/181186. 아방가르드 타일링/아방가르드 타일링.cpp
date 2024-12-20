#include<vector>

using namespace std;

const long long divValue = 1000000007;

int solution(int n) {
	vector<long long> dp(100001, 0);
	vector<long long> ndp(100001, 0);
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 10;
    ndp[0] = 1;
	ndp[1] = 1;
	ndp[2] = 3;
	ndp[3] = 11;

	for (int i = 4; i <= n; i++)
	{
		dp[i] += dp[i - 1];
		dp[i] += dp[i - 3];
		dp[i] += ndp[i - 2] * 2;
		dp[i] += ndp[i - 3] * 4;
		dp[i] += ndp[i - 4] * 2;
		dp[i] %= divValue;

		ndp[i] += ndp[i - 3];
		ndp[i] += dp[i];
		ndp[i] %= divValue;

	}

	return dp[n] % divValue;
}