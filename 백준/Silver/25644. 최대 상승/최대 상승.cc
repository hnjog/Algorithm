#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec;
	vector<int> dp(n,0);

	for (int i = 0; i < n;i++)
	{
		int t;
		cin >> t;
		vec.push_back(t);
	}

	int minV = vec[0];

	for (int i = 1; i < n; i++)
	{
		if (minV > vec[i])
			minV = vec[i];

		dp[i] = max(dp[i - 1], vec[i] - minV);
	}

	cout << dp[n-1];
}