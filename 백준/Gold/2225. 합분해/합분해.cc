#include<iostream>
#include<vector>

using namespace std;

const int divV = 1000000000;

long dp[201][201] = {0,};

long recur(int n,int k)
{
	if (k == 0)
		return 0;

	if (k == 1)
		return 1;

	if (dp[n][k] != 0)
		return dp[n][k];

	for (int i = 0; i <= n; i++)
	{
		dp[n][k] += recur(i, k - 1);
		dp[n][k] %= divV;
	}

	return dp[n][k] % divV;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << recur(n,k);

	return 0;
}