#include<iostream>

using namespace std;

int dp[1001] = { 0, };

const int mod = 10007;

int func(int n)
{
	if (dp[n] != 0)
		return dp[n];

	dp[n] = (func(n - 1) + func(n - 2) * 2) % mod;

	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;

	cout << func(n);
}