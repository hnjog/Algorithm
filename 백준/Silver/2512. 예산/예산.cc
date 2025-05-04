#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec;
	int fullS = 0;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		vec.push_back(t);
		fullS += t;
	}

	int maxS;
	cin >> maxS;

	sort(vec.begin(), vec.end());
	if (maxS >= fullS)
	{
		cout << vec.back();
		return 0;
	}

	int low = 0, high = vec.back();
	while (low < high)
	{
		int mid = (low + high) / 2;
		int s = 0;

		for (int i = 0; i < n; i++)
		{
			s += min(mid, vec[i]);
		}

		if (s > maxS)
		{
			high = mid;
		}
		else
		{
			if (low == mid)
				break;
			low = mid;
		}


	}

	cout << low;
}