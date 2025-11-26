#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int main()
{
	int d, p;
	cin >> d >> p;

	vector<long> lens, caps;

	for (int i = 0; i < p; i++)
	{
		long l, c;
		cin >> l >> c;
		lens.push_back(l);
		caps.push_back(c);
	}

	vector<long> dp(d + 1,-1);
	dp[0] = INT_MAX;

	for (int i = 0; i < p; i++)
	{
		long nowl = lens[i];
		long nowc = caps[i];

		for (int j = d; j >= nowl; j--)
		{
			long mv = min(dp[j - nowl], nowc);

			dp[j] = max(dp[j], mv);
		}
	}

	cout << dp[d];

	return 0;
}