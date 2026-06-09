#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

int GetPoint(int mid, int last, int work)
{
	return mid * 35 / 100 + last * 45 / 100 + work * 20 / 100;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	const string pointStr[10] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, k;
		cin >> n >> k;
		k--;
		vector<pii> points(n);

		for (int i = 0; i < n; i++)
		{
			int m, l, w;
			cin >> m >> l >> w;
			points[i].second = GetPoint(m, l, w);
			points[i].first = i;
		}

		sort(points.begin(), points.end(),
			[](const pii& a, const pii& b) 
			{
				return a.second > b.second;
			}
			);

		int idx = 0;
		int count = 0;
		int clim = n / 10;

		for (pii& p : points)
		{
			if (p.first == k)
			{
				break;
			}

			count++;
			if (count >= clim)
			{
				idx++;
				count = 0;
			}
		}


		cout << '#' << test_case << ' ' << pointStr[idx] << '\n';
	}
	return 0;
}