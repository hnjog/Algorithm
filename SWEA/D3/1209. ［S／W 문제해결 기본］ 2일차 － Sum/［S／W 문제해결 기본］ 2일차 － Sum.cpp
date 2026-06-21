#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int t;
		cin >> t;
		vector<vector<int>> arr(100, vector<int>(100,0));

		int best = 0;

		for (int i = 0; i < 100; i++)
		{
			int ho = 0;
			for (int j = 0; j < 100; j++)
			{
				cin >> arr[i][j];
				ho += arr[i][j];
			}
			best = max(ho, best);
		}

		for (int i = 0; i < 100; i++)
		{
			int ve = 0;
			for (int j = 0; j < 100; j++)
			{
				ve += arr[j][i];
			}
			best = max(ve, best);
		}

		int v1 = 0, v2 = 0;
		for (int i = 0; i < 100; i++)
		{
			v1 += arr[i][i];
			v2 += arr[i][99 - i];
		}

		best = max(v1, best);
		best = max(v2, best);

		cout << '#' << t << ' ' << best << '\n';
	}
	return 0;
}