class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		set<int> valset;
		
		for (int i : nums)
		{
			if (i > 0)
				valset.insert(i);
		}

		int idx = 1;
		for (int val : valset)
		{
			if (idx != val)
			{
				break;
			}
			idx++;
		}

		return idx;
	}
};