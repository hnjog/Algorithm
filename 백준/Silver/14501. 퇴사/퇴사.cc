#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pii;

int dp[17] = { 0, };
int n = 0;

int func(const vector<pii>& vec, int nowDay)
{
	if (nowDay > n)
		return 0;

	if (vec[nowDay].first + nowDay <= n &&
		vec[nowDay].first != 0)
	{
		dp[vec[nowDay].first + nowDay] = max(dp[vec[nowDay].first + nowDay], dp[nowDay] + vec[nowDay].second);
		func(vec, vec[nowDay].first + nowDay);
	}

	if(nowDay != 0)
		dp[nowDay] = max(dp[nowDay - 1],dp[nowDay]);

	return func(vec, nowDay + 1);
}

int main()
{
	cin >> n;

	vector<pii> vec;
	for (int i = 0; i < n; i++)
	{
		pii p;
		cin >> p.first >> p.second;
		vec.push_back(p);
	}
	vec.push_back({ 0,0 });

	func(vec, 0);

	cout << dp[n];
}