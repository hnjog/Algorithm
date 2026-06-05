#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> counts(101, 0);
		int k;
		cin >> k;

		for (int i = 0; i < 100; i++)
		{
			int t;
			cin >> t;
			counts[t]++;
		}

		int l = 1;
		int r = 100;

		while (k > 0 &&
			l < r)
		{
			while (counts[l] == 0)
			{
				l++;
			}

			while (counts[r] == 0)
			{
				r--;
			}

			if (l >= r)
				break;

			counts[l]--;
			counts[r]--;
			counts[l + 1]++;
			counts[r - 1]++;
			k--;
		}

		while (counts[l] == 0)
		{
			l++;
		}

		while (counts[r] == 0)
		{
			r--;
		}

		int count = (r - l) <= 0 ? 0 : r - l;

		cout << '#' << test_case << ' ' << count << '\n';
	}
	return 0;
}