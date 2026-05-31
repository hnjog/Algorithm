#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> Get90(vector<vector<int>>& maps)
{
	int n = maps.size();
	vector<vector<int>> ret;
	ret.reserve(n);
	for (int i = 0; i < n; i++)
	{
		ret.push_back(vector<int>());
		ret[i].reserve(n);
		for (int j = n - 1; j >= 0; j--)
		{
			ret[i].push_back(maps[j][i]);
		}
	}

	return ret;
}

vector<vector<int>> Get180(vector<vector<int>>& maps)
{
	int n = maps.size();
	vector<vector<int>> ret;
	ret.reserve(n);
	for (int i = 0; i < n; i++)
	{
		ret.push_back(vector<int>());
		ret[i].reserve(n);
		for (int j = n - 1; j >= 0; j--)
		{
			ret[i].push_back(maps[n - i - 1][j]);
		}
	}

	return ret;
}

vector<vector<int>> Get270(vector<vector<int>>& maps)
{
	int n = maps.size();
	vector<vector<int>> ret;
	ret.reserve(n);
	for (int i = 0; i < n; i++)
	{
		ret.push_back(vector<int>());
		ret[i].reserve(n);
		for (int j = 0; j < n; j++)
		{
			ret[i].push_back(maps[j][n - i - 1]);
		}
	}

	return ret;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<vector<int>> maps(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> maps[i][j];
			}
		}

		cout << '#' << test_case << '\n';

		vector < vector<int>> r1 = Get90(maps);
		vector < vector<int>> r2 = Get180(maps);
		vector < vector<int>> r3 = Get270(maps);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << r1[i][j];
			}

			cout << ' ';

			for (int j = 0; j < n; j++)
			{
				cout << r2[i][j];
			}

			cout << ' ';

			for (int j = 0; j < n; j++)
			{
				cout << r3[i][j];
			}

			cout << '\n';
		}

	}
	return 0;
}