#include<iostream>
#include<vector>

using namespace std;

int dp[46] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,};

int func(int n)
{
	if (dp[n] != 0)
		return dp[n];

	return dp[n] = func(n - 1) + func(n - 2);
}

int main()
{
	int n;
	cin >> n;

	cout << func(n);
}