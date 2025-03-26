#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;

ull distance(pair<long, long>& v1, pair<long, long>& v2)
{
	return (v2.first - v1.first) * (v2.first - v1.first) + (v2.second - v1.second) * (v2.second - v1.second);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> x3 >> y3;
		cin >> x4 >> y4;

		vector<pair<long, long>> vp;
		vp.push_back({ x1,y1 });
		vp.push_back({ x2,y2 });
		vp.push_back({ x3,y3 });
		vp.push_back({ x4,y4 });
		sort(vp.begin(), vp.end());

		ull a = distance(vp[0], vp[1]);
		ull b = distance(vp[0], vp[2]);
		ull c = distance(vp[3], vp[1]);
		ull d = distance(vp[3], vp[2]);

		if (a == b &&
			b == c &&
			c == d)
		{
			ull e = distance(vp[0], vp[3]);
			ull f = distance(vp[2], vp[1]);
			if (e == f)
			{
				cout << 1 << '\n';
				continue;
			}
		}

		cout << 0 << '\n';

	}

}