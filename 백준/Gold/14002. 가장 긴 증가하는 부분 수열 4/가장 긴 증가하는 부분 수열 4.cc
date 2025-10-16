#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vecs(n);

	for (int i = 0; i < n; i++)
		cin >> vecs[i];

	if (n == 1)
	{
		cout << 1 << '\n';
		cout << vecs[0];
		return 0;
	}

	vector<pair<int, int>> dp(n);
	dp[0] = { 1, 0 };

	for (int i = 1; i < n; i++)
	{
		dp[i] = { 1,i };

		for (int j = i - 1; j >= 0; j--)
		{
			if (vecs[i] > vecs[j] &&
				dp[i].first <= dp[j].first)
			{
				dp[i].first = dp[j].first + 1;
				dp[i].second = j;
			}
		}
	}

	int ans = 0;
	int sIdx = 0;

	for (int i = 0; i < n; i++)
	{
		if (ans < dp[i].first)
		{
			ans = dp[i].first;
			sIdx = i;
		}
	}

	cout << ans << '\n';
	stack<int> st;

	int next = sIdx;

	while (next != dp[next].second)
	{
		st.push(next);
		next = dp[next].second;
	}

	st.push(next);

	while (st.empty() == false)
	{
		cout << vecs[st.top()] << ' ';
		st.pop();
	}

	return 0;
}