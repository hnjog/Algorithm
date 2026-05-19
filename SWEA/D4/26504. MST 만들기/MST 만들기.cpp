#include<iostream>
#include<vector>
#include<algorithm>

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
		int m = n * (n - 1) / 2;

		vector<long long> val(m);
		for (int i = 0; i < m; i++)
			cin >> val[i];

		sort(val.begin(), val.end(), less<int>());

		long long minV = 0;
		for (int i = 0; i < n - 1; i++)
			minV += val[i];

		int step = 0;
		long long maxV = 0;

		for (int i = 0; i < m; i++)
		{
			step += i;
			if (step >= m)
				break;
			maxV += val[step];
		}

		cout << minV << ' ' << maxV << '\n';
	}
	return 0;
}