#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;

		unordered_set<int> um;
		for (int j = 0; j < n; j++)
		{
			int v;
			cin >> v;
			um.insert(v);
		}

		int m;
		cin >> m;

		for (int j = 0; j < m; j++)
		{
			int v;
			cin >> v;
			if (um.find(v) == um.end())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << 1 << '\n';
			}
		}
	}
}