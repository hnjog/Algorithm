#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isGood(vector<int>& nums, int nowIdx)
{
	int nowV = nums[nowIdx];
	int n = nums.size();

	int left = 0;
	if (left == nowIdx)
		left++;
	int right = n - 1;
	if (right == nowIdx)
		right--;

	while (left < right)
	{
		int sum = nums[left] + nums[right];

		if (sum == nowV)
			return true;

		if (sum > nowV)
		{
			right--;
			if (right == nowIdx)
				right--;
		}
		else
		{
			left++;
			if (left == nowIdx)
				left++;
		}

	}

	return false;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	if (n <= 2)
	{
		cout << 0;
		return 0;
	}

	sort(nums.begin(), nums.end());

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		if (isGood(nums, i))
		{
			ans++;
		}
	}

	cout << ans;

	return 0;
}