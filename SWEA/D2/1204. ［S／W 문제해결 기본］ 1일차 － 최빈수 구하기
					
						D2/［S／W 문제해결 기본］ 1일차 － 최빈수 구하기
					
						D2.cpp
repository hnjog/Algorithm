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
		int t;
		cin >> t;
		cout << '#' << t << ' ';
		vector<int> vals(101, 0);

		for (int i = 0; i < 1000; i++)
		{
			int v;
			cin >> v;
			vals[v]++;
		}

		int bestV = -1;
		int bestAmount = 0;

		for (int i = 100; i >= 0; i--)
		{
			if (vals[i] > bestAmount)
			{
				bestV = i;
				bestAmount = vals[i];
			}
		}

		cout << bestV << '\n';
	}
	return 0;
}