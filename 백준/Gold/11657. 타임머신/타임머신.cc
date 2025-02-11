#include<iostream>
#include<unordered_map>
#include<vector>
#include<limits.h>

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	unordered_map<ll, vector<ll>>edge;

	vector<ll> vec(n + 1, LONG_MAX);

	

	for (int i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;

		edge[i].push_back(a);
		edge[i].push_back(b);
		edge[i].push_back(c);
	}

	vec[1] = 0;

	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int start = edge[j][0];
			int to = edge[j][1];
			int cost = edge[j][2];

			if (vec[start] == LONG_MAX)
				continue;

			if (vec[to] > vec[start] + cost)
				vec[to] = vec[start] + cost;
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		int start = edge[i][0];
		int to = edge[i][1];
		int cost = edge[i][2];

		if (vec[start] == LONG_MAX)
			continue;

		if (vec[to] > vec[start] + cost)
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (vec[i] == LONG_MAX)
			cout << -1 << '\n';
		else
			cout << vec[i] << '\n';
	}

}