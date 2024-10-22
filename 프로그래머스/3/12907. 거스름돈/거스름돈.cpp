#include <vector>
#include<algorithm>

using namespace std;

const int divV = 1000000007;

int solution(int n, vector<int> money) {
	vector<long> dp(n + 1, 0);

	sort(money.begin(), money.end());

	int mSize = money.size();

	for (int i = 0; i < mSize; i++)
	{
		if (money[i] > n)
			break;

		dp[money[i]]++;

		for (int j = 1; j <= n; j++)
		{
			if (j - money[i] >= 0)
			{
				dp[j] += dp[j - money[i]];
				dp[j] %= divV;
			}
		}
	}

	return dp[n];
}