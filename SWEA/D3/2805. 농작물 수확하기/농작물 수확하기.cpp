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

		vector<vector<int>> maps(n,vector<int>(n,0));
		for (int i = 0; i < n; i++)
		{
			string t;
			cin >> t;

			for (int j = 0; j < n; j++)
			{
				maps[i][j] = t[j] - '0';
			}
		}

		int ret = 0;

		for (int i = 0; i < n; i++)
		{
			int start = abs(i - n / 2);
			int end = n - start - 1;
			
			for (int j = start; j <= end; j++)
			{
				ret += maps[i][j];
			}
		}

		cout << '#' << test_case << ' ' << ret << '\n';

	}
	return 0;
}