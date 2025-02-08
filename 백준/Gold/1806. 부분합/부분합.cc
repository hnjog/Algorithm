#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;

	vector<long> vec;
	for (int i = 0; i < n; i++)
	{
		long t;
		cin >> t;
		vec.push_back(t);
	}

	int left = 0, right = 0;
	long sum = 0;
	bool needSum = true;

	int m = n + 1;
	while (left < n)
	{
		long lv = vec[left];
		long rv = vec[right];
		if (lv >= s || rv >= s)
		{
			m = 1;
			break;
		}

		if (needSum)
		{
			sum += rv;
			right++;
		}
		else
		{
			sum -= lv;
			left++;
		}

		if (sum >= s)
		{
			needSum = false;
			m = min(m, right - left);
		}
		else
		{
			needSum = true; 
			if (right == n)
				break;
		}
	}

	if (m == n + 1)
		cout << 0;
	else
		cout << m;

}