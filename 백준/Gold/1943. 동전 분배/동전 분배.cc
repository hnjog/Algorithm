#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int idx = 0;

	while (idx < 3)
	{
		int n;
		cin >> n;
		vector<int> coins;
		vector<int> counts;

		int maxV = 0;

		for (int i = 0; i < n; i++)
		{
			int v, c;
			cin >> v >> c;

			coins.push_back(v);
			counts.push_back(c);

			for (int j = 0; j < c; j++)
			{
				maxV += v;
			}
		}

		if (maxV % 2 == 1)
		{
			cout << 0 << '\n';
			idx++;
			continue;
		}

		// n개의 동전 사용하여 총 합의 절반인 targetV를 표현할 수 있는가?
		int targetV = maxV / 2;
		vector<vector<bool>> dp(n + 1, vector<bool>(targetV + 1, false));

		dp[0][0] = true;

		bool bFind = false;

		for (int i = 1; i <= n; i++)
		{
			int nowCoinV = coins[i - 1];
			int nowCoinC = counts[i - 1];

			for (int j = targetV; j >= 0; j--)
			{
				for (int k = nowCoinC; k >= 0; k--)
				{
					int tj = j - k * nowCoinV;

					if (tj >= 0 &&
						dp[i-1][tj])
					{
						dp[i][j] = true;
						if (j == targetV)
							bFind = true;
						break;
					}
				}

				if (bFind)
					break;
			}
			if (bFind)
				break;
		}

		if (bFind)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';

		idx++;
	}

	return 0;
}