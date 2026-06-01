#include<iostream>
#include<vector>

using namespace std;

typedef pair<long, long> pii;

int main(long argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		long num, limitCal;
		cin >> num >> limitCal;

		vector<pii> ingreds(num);

		vector<int> limits(limitCal + 1, 0);

		for (int i = 0; i < num; i++)
		{
			cin >> ingreds[i].first >> ingreds[i].second;
		}

		for (int i = 0; i < num; i++)
		{
			int val = ingreds[i].first;
			int cal = ingreds[i].second;
			for (int j = limitCal; j >= cal; j--)
			{
				limits[j] = max(limits[j], limits[j - cal] + val);
			}
		}

		cout << '#' << test_case << ' ' << limits[limitCal] << '\n';
	}
	return 0;
}