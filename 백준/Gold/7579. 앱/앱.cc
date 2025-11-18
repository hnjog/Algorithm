#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<long long> weights, vals;
	int maxV = 0;

	for (int i = 0; i < n; i++)
	{
		long long w;
		cin >> w;
		weights.push_back(w);
	}

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		vals.push_back(v);
		maxV += v;
	}

	// 특정 수치값을 비활성화했을때 얻을 수 있는
	// 메모리의 양
	// dp[i] : i만큼 비활성화 하였을때 얻을 수 있는 최대 메모리 양
	vector<long long> dp(maxV + 1, 0);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = maxV; j >= vals[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - vals[i]] + weights[i]);
		}
	}

	for (int i = 0; i <= maxV; i++)
	{
		if (dp[i] >= m)
		{
			cout << i;
			break;
		}
	}

	return 0;
}