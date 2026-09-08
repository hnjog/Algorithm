class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count =0;
        int ns = nums.size();
        int si = ns - 1;
        for(int i=0;i<=si;i++)
        {
            if(nums[i] == val)
            {
                swap(nums[i],nums[si]);
                si--;
                i--;
                count++;
            }
        }

        while(count > 0)
        {
            count--;
            nums.pop_back();
        }

        return nums.size();
    }
};