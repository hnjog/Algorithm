#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void dfs(vector<int>& v, int now, vector<bool>& visit, int& ans, queue<int>& visitQ)
{
	if (visit[now] == true)
	{
		while (visitQ.empty() == false &&
			visitQ.front() != now)
		{
			visitQ.pop();
		}
		ans -= visitQ.size();
		return;
	}

	visit[now] = true;
	visitQ.push(now);
	dfs(v, v[now], visit, ans, visitQ);

	return;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t > 0)
	{
		int n;
		cin >> n;
		vector<int> wants(n);
		vector<bool> visit(n);

		int ans = n;

		for (int i = 0; i < n; i++)
		{
			cin >> wants[i];
			wants[i]--;
			if (wants[i] == i)
			{
				visit[i] = true;
				ans--;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (visit[i] == false)
			{
				queue<int> q;
				dfs(wants, i, visit, ans, q);
			}
		}

		cout << ans << '\n';
		t--;
	}

	return 0;
}