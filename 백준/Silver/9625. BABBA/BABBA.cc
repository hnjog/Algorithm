#include<iostream>

using namespace std;

typedef pair<int, int> pii;

pii dp[46];

pii func(int n)
{
	if (dp[n] != make_pair(0, 0))
		return dp[n];

	dp[n].first = func(n - 1).second;
	dp[n].second = func(n - 1).first + dp[n].first;

	return dp[n];
}

int main()
{
	int n;
	cin >> n;
	int a = 1, b = 0;
	dp[0] = { 1,0 };
	dp[1] = { 0,1 };
	pii ans = func(n);
	cout << ans.first << ' ' << ans.second;
}