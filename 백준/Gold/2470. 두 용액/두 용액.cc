#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<long> vec(n, 0);

	for (int i = 0; i < n; i++)
	{
		long t;
		cin >> t;
		vec[i] = t;
	}

	sort(vec.begin(), vec.end());

	int left = 0, right = n - 1;
	pair<long, long> p;
	long sumV = INT_MAX;

	while (left < right)
	{
		long lv = vec[left];
		long rv = vec[right];
		long s = lv + rv;

		if (sumV > abs(s))
		{
			sumV = abs(s);
			p.first = lv;
			p.second = rv;
		}

		if (s == 0)
			break;

		if (s > 0)
			right--;
		else
			left++;
	}

	cout << p.first << ' ' << p.second;
}