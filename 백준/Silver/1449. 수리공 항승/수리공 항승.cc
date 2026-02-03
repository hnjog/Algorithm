#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;
	vector<int> vv(n);
	for (int i = 0; i < n; i++)
		cin >> vv[i];

	sort(vv.begin(), vv.end());

	double nowEnd = vv[0] - 0.5 + l;
	int count = 1;

	for (int i = 1; i < n; i++)
	{
		int now = vv[i];

		if (double(now) < nowEnd)
		{
			continue;
		}

		count++;
		nowEnd = vv[i] - 0.5 + l;
	}

	cout << count;

	return 0;
}