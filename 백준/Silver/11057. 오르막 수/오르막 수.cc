#include<iostream>
#include<vector>

using namespace std;

const int divV = 10007;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> dp(n,vector<int>(10,0));
	for (int i = 0; i < 10; i++)
	{
		dp[0][i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += (dp[i - 1][k] % divV);
				dp[i][j] %= divV;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++)
    {
		sum += dp[n - 1][i];
        sum %= divV;
    }

	cout << sum;

	return 0;
}