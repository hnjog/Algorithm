#include<iostream>
#include<vector>

using namespace std;

int FindIdx(vector<int>& arr, int v)
{
	int left = 0, right = arr.size() - 1;

	while (left < right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] == v)
			return mid;

		if (arr[mid] > v)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}

	}

	return left;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> ret;
	ret.push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		if (ret.back() < arr[i])
		{
			ret.push_back(arr[i]);
		}
		else
		{
			int idx = FindIdx(ret, arr[i]);
			ret[idx] = arr[i];
		}
	}

	cout << ret.size();

	return 0;
}