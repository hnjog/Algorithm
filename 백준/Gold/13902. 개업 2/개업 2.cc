#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	//
	// 생각해볼 점
	// 가능한 모든 수의 m개의 종류에 대하여
	// 횟수마다 각각의 조합을 기록해야 함
	// 
	// dp[i] : i값 만드는데 필요한 횟수
	// 
	// n까지로 반복하되 n이 발견되면 즉시 break 하는 방식
	// 
	// 웍 기준으로 순회
	// 
	// - 1을 사용하였을때
	//  dp[1] = 1 (현재 count)가 될것
	// 
	// 2개의 웍만 사용가능
	// 
	//

	vector<int> ws(m);
	unordered_set<int> possibles;
	for (int i = 0; i < m; i++)
	{
		cin >> ws[i];
		possibles.insert(ws[i]);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (ws[i] + ws[j] > n)
				continue;

			possibles.insert(ws[i] + ws[j]);
		}
	}

	vector<int> dp(n + 1, -1);
	dp[0] = 0;

	bool bFind = false;

	for (int i = 0; i <= n; i++)
	{
		for(int p : possibles)
		{
			if (i - p < 0)
				continue;

			if (dp[i - p] == -1)
				continue;

			if (dp[i] == -1)
				dp[i] = dp[i - p] + 1;
			else
				dp[i] = min(dp[i], dp[i - p] + 1);
		}
	}

	cout << dp[n];
	
	return 0;
}