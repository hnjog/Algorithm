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
		vector<pair<int, int>> pv(n);
		for (int i = 0; i < n; i++)
			cin >> pv[i].first >> pv[i].second;

		sort(pv.begin(), pv.end(), [](const pair<int,int>& a, const pair<int, int>& b) {
			if (a.second == b.second)
				return a.first > b.first;
			return a.second > b.second;
			});

		int now = pv[0].second;

		for (auto& p : pv)
		{
			now = min(p.second, now);
			int m = p.first;

			now -= m;
		}

		cout << now << '\n';
	}
	return 0;
}