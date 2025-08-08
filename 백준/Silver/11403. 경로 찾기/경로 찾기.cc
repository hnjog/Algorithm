#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	const int semiV = INT_MAX / 2;

	vector<vector<int>> results(n, vector<int>(n, semiV));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t;
			cin >> t;
			if(t == 1)
				results[i][j] = t;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (results[i][k] + results[k][j] < results[i][j])
				{
					results[i][j] = results[i][k] + results[k][j];
				}

			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (results[i][j] == semiV)
				cout << 0 << ' ';
			else
				cout << 1 << ' ';
		}
		cout << '\n';
	}

}