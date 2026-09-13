class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int idx = 0;idx < nums.size();idx++)
        {
            if(nums[idx] >= target)
                return idx;
        }

        return nums.size();
    }
};