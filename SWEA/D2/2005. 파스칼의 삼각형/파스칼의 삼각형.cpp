#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;

		vector<vector<int>> vals(n);
		vals[0].push_back(1);
		for (int i = 0; i < n - 1; i++)
		{
			vals[i + 1].reserve(i + 2);
			vals[i + 1].push_back(vals[i][0]);
			if (vals[i].size() >= 2)
			{
				for (int j = 0; j < vals[i].size() - 1; j++)
				{
					vals[i + 1].push_back(vals[i][j] + vals[i][j + 1]);
				}
			}
			vals[i + 1].push_back(vals[i].back());
		}

		cout << '#' << test_case << '\n';

		for (int i = 0; i < n; i++)
		{
			for (int v : vals[i])
			{
				cout << v << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}