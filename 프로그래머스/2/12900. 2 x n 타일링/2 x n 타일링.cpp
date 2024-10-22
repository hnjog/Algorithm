#include <vector>

using namespace std;

const int divV = 1000000007;

int solution(int n) {
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % divV;
	}

	return dp[n];
}