#include<iostream>
#include<vector>

using namespace std;

int GetMax(vector<vector<int>>& maps, int m)
{
	int n = maps.size();
	int maxV = 0;

	for (int i = 0; i <= n-m; i++)
	{
		for (int j = 0; j <= n - m; j++)
		{
			int v = 0;
			for (int y = i; y < i + m; y++)
			{
				for (int x = j; x < j + m; x++)
				{
					v += maps[y][x];
				}
			}

			if (v > maxV)
				maxV = v;
		}
	}

	return maxV;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		cin >> n >> m;

		vector<vector<int>> maps(n, vector<int>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> maps[i][j];
			}
		}

		cout << '#' << test_case << ' ' << GetMax(maps, m) << '\n';
	}
	return 0;
}