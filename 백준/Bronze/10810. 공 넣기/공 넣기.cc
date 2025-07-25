#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;

	vector<int> vec(n + 1);

	for (int i = 0; i < m; i++)
	{
		int t, u, v;
		cin >> t >> u >> v;
		for (int j = t; j <= u; j++)
		{
			vec[j] = v;
		}
	}

	for (int i = 1; i <=n;i++)
	{
		int v = vec[i];
		cout << v << ' ';
	}

	return 0;
}