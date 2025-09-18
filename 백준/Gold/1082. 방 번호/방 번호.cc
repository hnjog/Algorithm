#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string comp(const string& a, const string& b)
{
	if (a.size() != b.size())
	{
		if (a.size() > b.size())
			return a;

		return b;
	}

	if (a > b)
		return a;

	return b;
}

int main()
{
	int n;
	cin >> n;
	vector<int> costs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> costs[i];
	}

	int money;
	cin >> money;

	vector<string> dp(money + 1,"");

	for (int i = 0; i <= money; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + costs[j] <= money)
			{
				string a = dp[i] + to_string(j);
				sort(a.rbegin(), a.rend());
				if (a[0] == '0')
					a = "0";
				dp[i + costs[j]] = comp(dp[i + costs[j]], a);
			}
		}
	}

	cout << dp[money];

	return 0;
}