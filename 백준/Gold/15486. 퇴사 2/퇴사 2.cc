#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// dp[i] : i번째 일자에 얻을 수 있는 최대 금액
	// 
	// 진행?
	// dp[j + t[i]] = max(dp[j+t[i]],dp[j] + p[i])
	// 
	// 일단 해당 날짜에 '끝'나므로,
	// 
	// j 기준 내림차순이 맞아 보임
	// (일을 반복해서 할 순 없으므로)
	// 
	// 다만
	// i가 곧 진행일자이기에
	// j가 i까지만 내려와야 할듯?
	// 
	// 고민할점
	// - i번째 요소를 진행할때,
	//   i-1번째 요소가 고려되지 않는 듯함
	//   (ex : 8일이 있다고 1 - 3, 2 - 5 가 진행 가능한 것은 아님)
	//   (배낭 문제가 아니므로)
	// 
	// dp[i] : i번째 일자부터 마지막 날까지 얻을 수 있는 최대 금액
	// 
	// 진행
	// dp[i] = max(dp[i+1]//선택 x, dp[i+t[i]] + p[i])
	// 
	//

	int n;
	cin >> n;
	vector<int> times, pays;
	for (int i = 0; i < n; i++)
	{
		int t, p;
		cin >> t >> p;

		times.push_back(t);
		pays.push_back(p);
	}

	vector<int> dp(n+1, 0);

	for (int i = n-1; i >= 0; i--)
	{
		if (i + times[i] > n)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], dp[i + times[i]] + pays[i]);
		}
	}

	cout << dp[0];

	return 0;
}