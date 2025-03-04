#include<iostream>

using namespace std;

int dp[11] = { 0, };

int func(int n)
{
	if (dp[n] != 0)
		return dp[n];

	return dp[n] = func(n - 1) + func(n - 2) + func(n - 3);
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	dp[1] = 1;
	dp[2] = 2; // 2, 1 + 1
	dp[3] = 4; // 3, 2 + 1, 1 + 2, 1+1+1

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		cout << func(n) << '\n';
	}
}