#include<iostream>
#include<vector>
#include<string>
#include <sstream>

using namespace std;

const int divV = 10007;

int main()
{
	string l;
	getline(cin, l);
	stringstream starts(l);
	int n, m,h;
	starts >> n;
	starts >> m;
	starts >> h;

	vector<vector<int>> blocks(n, vector<int>());

	for (int i = 0; i < n; i++)
	{
		getline(cin, l);
		stringstream ss(l);

		int t;
		while (ss >> t)
		{
			blocks[i].push_back(t);
		}
	}

	// dp[i][j] : i번째의 사람까지 만들 수 있는 j값의 경우의 수
	// dp[i-1][j]를 사실상 가져와야 함 (+=)
	vector<vector<int>> dp(n + 1, vector<int>(h + 1, 0));

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		vector<int>& nowBlocks = blocks[i - 1];
		int nSize = nowBlocks.size();

		for (int j = 0; j <= h; j++)
		{
			if (dp[i - 1][j] <= 0)
				continue;

			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= divV;

			for (int nV : nowBlocks)
			{
				if (j + nV > h)
					continue;

				dp[i][j + nV] += dp[i - 1][j];
				dp[i][j + nV] %= divV;
			}
		}
	}

	cout << dp[n][h] % divV;

	return 0;
}