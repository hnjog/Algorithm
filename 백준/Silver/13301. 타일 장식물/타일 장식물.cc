#include<iostream>

using namespace std;

typedef unsigned long long ull;

ull dp[81] = {0,};

ull func(int n)
{
	if (n <= 0)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	return dp[n] = func(n - 1) + func(n - 2);
}

int main()
{
	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = dp[2] = 1;

	ull a = func(n);
	ull b = func(n-1) + a;

	cout << a * 2 + b * 2;
}