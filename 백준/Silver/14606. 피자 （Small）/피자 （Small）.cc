#include<iostream>

using namespace std;

int dp[11] = { 0, };

int func(int n)
{
	if (n <= 1)
		return 0;

	if (dp[n] != 0)
	{
		return dp[n];
	}

	int half1 = n / 2;
	int half2 = half1;
	
	if (n % 2 != 0)
		half2++;

	dp[n] = half1 * half2;
	dp[n] += func(half1);
	dp[n] += func(half2);

	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	dp[2] = 1;
	cout << func(n);
}