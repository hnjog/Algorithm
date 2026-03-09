#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> vv(n, vector<int>(n,0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> vv[j][i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		int v = INT_MIN;
		int vi = -1;

		for (int j = 0; j < n; j++)
		{
			if (vv[j].empty())
				continue;

			if (vv[j].back() > v)
			{
				v = vv[j].back();
				vi = j;
			}
		}

		vv[vi].pop_back();
		if (i == n - 1)
		{
			cout << v;
		}
	}

	return 0;
}