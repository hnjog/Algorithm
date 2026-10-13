class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int v = 0;

        for(int n : nums)
        {
            if(v == n)
                v++;
            else
                break;
        }

        return v;
    }
};