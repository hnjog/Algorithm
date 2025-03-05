#include<iostream>

using namespace std;

int dp[1001] = { 0, };

const int mod = 10007;

int func(int n)
{
	if (dp[n] != 0)
		return dp[n];

	return dp[n] = (func(n - 1) + func(n - 2)) % mod;
}

int main()
{
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;


	cout << func(n);
}