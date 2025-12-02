#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> buggers(n);
	int maxx = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> buggers[i];
		maxx += buggers[i];
	}

	// dp[i][j] : i 와 j로 분배가 가능하지 파악
	//
	// maxx - i - j = 길원이가 받을 햄버거 양
	//
	vector<vector<bool>> dp(maxx + 1, vector<bool>(maxx + 1, false));
	dp[0][0] = true;

	for (int i = 0; i < n; i++)
	{
		int nowBugger = buggers[i];
		for (int j = maxx; j >= 0; j--)
		{
			for (int k = maxx; k >= 0; k--)
			{
				if (j >= nowBugger &&
					dp[j-nowBugger][k])
				{
					dp[j][k] = true;
				}

				if (k >= nowBugger &&
					dp[j][k - nowBugger])
				{
					dp[j][k] = true;
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i <= maxx; i++)
	{
		for (int j = 0; j <= maxx - i; j++)
		{
			if (dp[i][j] == false)
				continue;

			int c = maxx - i - j;
			int v = min(i, j);
			v = min(v, c);

			if (v > ans)
				ans = v;
		}
	}

	cout << ans;
}