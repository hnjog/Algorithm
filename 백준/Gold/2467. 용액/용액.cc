#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long> v;

	for (int i = 0; i < n; i++)
	{
		long t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	if (v.back() <= 0)
	{
		cout << v[n - 2] << " " << v[n - 1];
		return 0;
	}
	long l1 = 0, l2 = 0;
	long lastV = LONG_MAX;

	int left = 0, right = n - 1;

	while (left < right)
	{
		long long lv = v[left] + v[right];

		if (abs(lv) <= abs(lastV))
		{
			lastV = lv;
			l1 = v[left];
			l2 = v[right];
		}

		if (abs(v[left]) < abs(v[right]))
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	cout << l1 << " " << l2;
}