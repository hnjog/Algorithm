#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector<int> weights, values;

	for (int i = 0; i < k; i++)
	{
		int l, t;
		cin >> l >> t;
		values.push_back(l);
		weights.push_back(t);
	}

	vector<int> dp(n + 1);

	for (int i = 0; i < k; i++)
	{
		for (int j = n; j >= weights[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
		}
	}

	cout << dp[n];

	return 0;
}