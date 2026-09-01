class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			int mv = nums[mid];

			if (mv == target)
				return mid;

			if (nums[left] <= mv)
			{
				if (nums[left] <= target &&
					target < mv)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else
			{
				if (mv < target &&
					target <= nums[right])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}

		}

		return -1;
	}
};