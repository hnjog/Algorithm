class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		queue<int> valIdxs;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != 0)
				valIdxs.push(i);
		}

		if (valIdxs.empty())
			return;

		for (int i = 0; i < nums.size(); i++)
		{
			if (valIdxs.empty() == false &&
				valIdxs.front() <= i)
				valIdxs.pop();

			if (nums[i] == 0 &&
				valIdxs.empty() == false)
			{
				swap(nums[i], nums[valIdxs.front()]);
				valIdxs.pop();
			}
		}
    }
};