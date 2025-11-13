#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;
	
	vector<int> weight, value;

	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		weight.push_back(w);
		value.push_back(v);
	}
	
	vector<int> dp(t + 1,0);

	for (int i = 0; i < n; i++)
	{
		for (int j = t; j >= weight[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	cout << dp[t];

	return 0;
}