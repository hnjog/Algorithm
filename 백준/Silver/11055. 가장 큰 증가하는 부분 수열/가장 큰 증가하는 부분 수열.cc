#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int recur(const vector<int>& vec, vector<int>& dp,int start)
{

	if (start < 0)
		return 0;

	if (dp[start] != 0)
		return dp[start];

	dp[start] = vec[start];
	
	for (int i = start - 1; i >= 0; i--)
	{
		if (vec[start] > vec[i])
		{
			// start가 자신 이전 위치에서
			// 자신보다 낮은값 발견 시,
			// 그 dp값을 자신에게 더함
			dp[start] = max(dp[start], recur(vec, dp, i) + vec[start]);
		}
	}

	return dp[start];
}

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	// 가장 '합'이 큰 LIS 의 합 구하기
	vector<int> dp(n);
	dp[0] = vec[0];

	// start = 0 ~ n까지 진행
	for (int i = 1; i < n; i++)
		recur(vec, dp, i);

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}