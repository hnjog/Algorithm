#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		t--;
		int n;
		cin >> n;

		vector<vector<ull>> sums(n, vector<ull>(n, LONG_MAX)); // 각 범위의 합들
		vector<vector<ull>> dp(n, vector<ull>(n, LONG_MAX)); // 합쳐지는 비용

		for (int i = 0; i < n; i++)
		{
			cin >> sums[i][i];
			dp[i][i] = 0;
		}

		for (int i = 0; i < n - 1; i++)
		{
			sums[i][i + 1] = sums[i][i] + sums[i + 1][i + 1];
			dp[i][i + 1] = sums[i][i + 1];
		}

		for (int size = 2; size < n; size++)
		{
			for (int i = 0; i < n - size; i++)
			{
				ull minV = LONG_MAX;
				sums[i][i + size] = sums[i][i] + sums[i + 1][i + size];
				
				for (int j = 0; j < size; j++)
				{
					ull temp1 = dp[i][i + j] + sums[i][i+j];
					ull temp2 = dp[i + j + 1][i + size] + sums[i+j+1][i+size];

					minV = min(minV, temp1 + temp2);
				}
				
				// dp[0][3]
				dp[i][i + size] = minV;
			}
		}

		cout << dp[0][n - 1] << '\n';
	}

	return 0;
}