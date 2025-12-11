#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	vector<long long> ret;
	long long dif = LONG_MAX;

	bool bFindz = false;

	for (int i = 0; i < n - 2; i++)
	{
		long long v1 = arr[i];
		int left = i + 1, right = n - 1;

		while (left < right)
		{
			long long v2 = arr[left];
			long long v3 = arr[right];
			long long d = (v1 + v2 + v3);

			if (dif > abs(d))
			{
				dif = abs(d);
				ret.clear();
				ret.push_back(v1);
				ret.push_back(v3);
				ret.push_back(v2);

				if (dif == 0)
				{
					bFindz = true;
					break;
				}
			}

			if (d < 0)
				left++;
			else
				right--;
		}

		if (bFindz)
			break;
	}

	sort(ret.begin(), ret.end());

	for (long long r : ret)
	{
		cout << r << ' ';
	}

	return 0;
}