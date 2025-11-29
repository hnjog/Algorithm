#include<iostream>
#include<vector>

using namespace std;

int main()
{
	/*
		dp[i][j] : i번째 파이프까지 사용하여 j 길이를 만들 수 있는 경우의 수

		점화식?
		dp[i][j] = dp[i][j-len[i]] + 1 (단 dp[i][j]를 만들 수 있다면)

		이거 for문 사용해서
		counts[i] 만큼 돌려야 함

		내림차순
	*/

	int n, x;
	cin >> n >> x;

	vector<int> lens(n);
	vector<int> counts(n);

	for (int i = 0; i < n; i++)
	{
		cin >> lens[i];
		cin >> counts[i];
	}

	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		int nowL = lens[i - 1];
		int nowC = counts[i - 1];

		for (int j = x; j >= 0; j--)
		{
			for (int k = 0; k <= nowC; k++)
			{
				if (j - nowL * k < 0)
					continue;

				dp[i][j] += dp[i-1][j - nowL * k];
			}
		}
	}

	cout << dp[n][x];

	return 0;
}