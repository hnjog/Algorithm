#include<iostream>
#include<algorithm>

using namespace std;

int dp[11] = { 0, };
const double ar[3] = { 1.05,1.2,1.35 };

void func(const int n, int now)
{
	if (now > n)
		return;

	if (now + 5 <= n)
		dp[now + 5] = max(dp[now + 5], int(dp[now] * ar[2]));

	if (now + 3 <= n)
		dp[now + 3] = max(dp[now + 3], int(dp[now] * ar[1]));

	if (now + 1 <= n)
		dp[now + 1] = max(dp[now + 1], int(dp[now] * ar[0]));

	func(n, now + 5);
	func(n, now + 3);
	func(n, now + 1);
}

int main()
{
	int m, n;
	cin >> m >> n;

	dp[0] = m;
	func(n, 0);

	cout << dp[n];
}