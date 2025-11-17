#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, k, x;
	cin >> n >> k >> x;

	vector<pair<int, int>> vals(n);

	for (int i = 0; i < n; i++)
		cin >> vals[i].first >> vals[i].second;

	int maxK = k * x;

	vector<vector<bool>> dp(k + 1, vector<bool>(maxK + 1, false));
	// dp[i][j] : i개를 골라 합이 j가 되는것이 가능한지의 여부
	dp[0][0] = true;

	for (int i = 0; i < n; i++)
	{
		for (int j = k; j > 0; j--)
		{
			for (int v = maxK; v >= vals[i].first; v--)
			{
				if (dp[j - 1][v - vals[i].first] == true)
				{
					// 해당 값을 만들 수 있음
					dp[j][v] = true;
				}
			}
		}
	}

	long long ret = 0;

	for (int i = 0; i <= maxK; i++)
	{
		if (dp[k][i] == false)
			continue;

		long long v1 = i;
		long long v2 = maxK - i;

		if (v1 * v2 > ret)
			ret = v1 * v2;
	}

	cout << ret;

	return 0;
}