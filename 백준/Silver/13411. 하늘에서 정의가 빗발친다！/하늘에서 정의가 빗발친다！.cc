#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	// index, 격추 시간
	vector<pair<int, long double>> vv;
	for (int i = 0; i < n; i++)
	{
		long long x, y, v;
		cin >> x >> y >> v;

		long long disS = x * x + y * y;
		long long vs = v * v;

		long double t = disS / (long double)vs;

		vv.push_back({ i + 1,t });
	}

	sort(vv.begin(), vv.end(), 
		[](const pair<int, long double>& a, const pair<int, long double>& b)
		{
			if (a.second == b.second)
				return a.first < b.first;

			return a.second < b.second;
		});

	for (auto& v : vv)
	{
		cout << v.first << '\n';
	}
}