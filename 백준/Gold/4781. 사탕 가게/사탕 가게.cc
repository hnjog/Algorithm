#include<iostream>
#include<vector>

using namespace std;

int main()
{
	while (true)
	{
		int n;
		double m;
		cin >> n >> m;

		if (n == 0)
			break;

		vector<int> weights;
		vector<int> vals;

		for (int i = 0; i < n; i++)
		{
			int t;
			double w;
			cin >> t >> w;
			vals.push_back(t);
			weights.push_back(w * 100 + 0.5);
		}

		int mv = m * 100 + 0.5;

		vector<int> dp(mv + 1);

		for (int i = 0; i < n; i++)
		{
			for (int j = weights[i]; j <= mv; j++)
			{
				dp[j] = max(dp[j], dp[j - weights[i]] + vals[i]);
			}
		}

		cout << dp[mv] << '\n';
	}

	return 0;
}