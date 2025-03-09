#include<iostream>

using namespace std;

typedef unsigned long long ul;

ul dp[92] = { 0, };

ul func(int n)
{
	if (dp[n] != 0)
		return dp[n];

	return dp[n] = func(n - 1) + func(n - 2);
}

int main()
{
	int n;
	cin >> n;

	dp[1] = dp[2] = 1;
	
	cout << func(n);
}