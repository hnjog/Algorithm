class Solution {
public:
	int waysToMakeFair(vector<int>& nums) {

		vector<int> oddSums, dSums;
		oddSums.push_back(0);
		dSums.push_back(0);

		for (int i = 1; i <= nums.size(); i++)
		{
			if (i % 2 == 0)
			{
				dSums.push_back(dSums.back() + nums[i - 1]);
				oddSums.push_back(oddSums.back());
			}
			else
			{
				oddSums.push_back(oddSums.back() + nums[i - 1]);
				dSums.push_back(dSums.back());
			}
		}

		int osv = 0;
		int dsv = 0;
		int count = 0;
		int n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			int to = osv + dSums[n] - dSums[i];
			int td = dsv + oddSums[n] - oddSums[i];

			if (to == td)
				count++;

			if (i % 2 == 0)
			{
				dsv += nums[i-1];
			}
			else
			{
				osv += nums[i-1];
			}
		}

		return count;
	}
};