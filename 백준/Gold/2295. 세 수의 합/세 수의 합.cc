#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long> arr;
	for (int i = 0; i < n; i++)
	{
		long l;
		cin >> l;
		arr.push_back(l);
	}

	sort(arr.begin(), arr.end());

	unordered_set<long> sets;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			sets.insert(arr[i] + arr[j]);
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		long maxS = arr[i];

		for (int j = 0; j <= i; j++)
		{
			long findv = maxS - arr[j];
			if (sets.find(findv) != sets.end())
			{
				cout << maxS;
				return 0;
			}
		}
	}

	return 0;
}