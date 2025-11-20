#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// 호텔의 고객을 C명 늘리기 위해
	// 호텔주인이 투자해야하는 최소 비용
	// 
	// 여러번 투자 가능
	// -> 나누기는 금지
	// 
	// 무한 dp 쪽
	// 
	//

	int c, n;
	cin >> c >> n;

	vector<int> costs, clients;

	for (int i = 0; i < n; i++)
	{
		int c1, c2;
		cin >> c1 >> c2;
		costs.push_back(c1);
		clients.push_back(c2);
	}

	int maxC = c + 1001;

	vector<int> dp(maxC + 1, 1e9);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = clients[i]; j <= maxC; j++)
		{
			dp[j] = min(dp[j], dp[j - clients[i]] + costs[i]);
		}
	}

	int ans = 1e9;

	for (int i = c; i <= maxC; i++)
	{
		if (ans > dp[i])
			ans = dp[i];
	}

	cout << ans;

	return 0;
}