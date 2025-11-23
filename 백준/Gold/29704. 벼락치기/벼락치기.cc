#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, t;
	cin >> n >> t;

	int maxV = 0;
	vector<int> vals, times;
	for (int i = 0; i < n; i++)
	{
		int d, m;
		cin >> d >> m;
		times.push_back(d);
		vals.push_back(m);
		maxV += m;
	}

	// dp[i] : i번째 일에서 가장 작은 수치의 값
	vector<int> dp(t + 1, maxV);
	
	for (int i = 0; i < n; i++)
	{
		int nowV = vals[i];
		int nowT = times[i];

		for (int j = t; j >= nowT; j--)
		{
			dp[j] = min(dp[j], dp[j - nowT] - nowV);
		}
	}

	cout << dp[t];

	return 0;
}