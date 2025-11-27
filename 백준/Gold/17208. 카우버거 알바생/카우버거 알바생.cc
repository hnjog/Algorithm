#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<int, int>> orders(n);

	for (int i = 0; i < n; i++)
	{
		cin >> orders[i].first >> orders[i].second;
	}

	vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

	for (int i = 0; i < n; i++)
	{
		int nowCh = orders[i].first;
		int nowFr = orders[i].second;

		for (int j = m; j >= nowCh; j--)
		{
			for (int v = k; v >= nowFr; v--)
			{
				dp[j][v] = max(dp[j][v], dp[j - nowCh][v - nowFr] + 1);
			}
		}
	}

	int ans = 0;

	for (auto& v : dp)
	{
		for (int i : v)
		{
			if (i > ans)
				ans = i;
		}
	}

	cout << ans;

	return 0;
}