using namespace std;

const long divV = 1000000007;
long long dp[5001] = { 0, };

int solution(int n) {
	// 홀수면 답 없음
	if (n % 2 == 1)
		return 0;

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2)
	{
		dp[i] = (dp[i - 2] * 4 % divV - (dp[i-4] % divV) + divV ) % divV;
	}

	return (int)dp[n];
}