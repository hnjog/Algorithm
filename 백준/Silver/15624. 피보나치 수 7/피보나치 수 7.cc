#include<iostream>

using namespace std;

int dp[1000005] = { 0, };
const int divV = 1000000007;

int fibo(int n)
{
    if (n == 0)
		return 0;
	if (dp[n] != 0)
		return dp[n];

	return dp[n] = (fibo(n - 1) + fibo(n - 2)) % divV;
}

int main()
{
	int n;
	cin >> n;
	dp[1] = dp[2] = 1;
	cout << fibo(n);
}