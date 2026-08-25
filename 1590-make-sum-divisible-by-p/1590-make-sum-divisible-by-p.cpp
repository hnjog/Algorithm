class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
		int remain = 0;
		for (int n : nums)
		{
			remain += n;
			remain %= p;
		}

		if (remain == 0)
			return 0;

		int curr = 0;

		unordered_map<int, int> umap;
		umap[0] = -1;

		int ret = nums.size();

		for (int i=0;i<nums.size();i++)
		{
			curr += nums[i];
			curr %= p;

			int v = curr - remain + p;
			v %= p;

			if (umap.find(v) != umap.end())
			{
				ret = min(ret, i - umap[v]);
			}

			umap[curr] = i;
		}

		if (ret == nums.size())
			return -1;

		return ret;
	}
};