class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> nc(nums.size(),0);
        vector<int> ret;

        for(int n : nums)
        {
            nc[n-1]++;
        }

        for(int i = 0; i <nc.size();i++)
        {
            if(nc[i] == 0)
                ret.push_back(i+1);
        }

        return ret;
    }
};