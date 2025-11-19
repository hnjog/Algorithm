#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long> bids(n);
	long fullW = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> bids[i];
		fullW += bids[i];
	}

	long t;
	cin >> t;
	vector<long> checks(t);

	for (int i = 0; i < t; i++)
	{
		cin >> checks[i];
	}

	// dp[i][w] : i번째의 추까지 사용하여 w 값을 표현 가능한가? (양 저울의 차가 w인가?)
	vector<vector<bool>> dp(n+1,vector<bool>(fullW + 1, false));

	dp[0][0] = true;

	for (int i = 1; i <= n; i++)
	{
		long nowBid = bids[i-1];

		for (int j = 0; j <= fullW; j++)
		{
			if (dp[i-1][j] == false)
				continue;

			// 추를 안올리는 경우
			dp[i][j] = true;

			// 추를 무거운 쪽에 올리는 경우
			if (j + nowBid <= fullW)
				dp[i][j + nowBid] = true;

			// 추를 가벼운 쪽에 올리는 경우
			if (abs(j - nowBid) <= fullW)
				dp[i][abs(j - nowBid)] = true;

		}
	}

	for (int i : checks)
	{
		if (i > fullW)
		{
			cout << "N ";
			continue;
		}

		if (dp[n][i])
		{
			cout << "Y ";
		}
		else
		{
			cout << "N ";
		}
	}

	return 0;
}