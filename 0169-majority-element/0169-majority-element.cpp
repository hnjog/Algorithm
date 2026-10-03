class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int n : nums)
        {
            um[n]++;
        }

        int count = 0;
        int ret = 0;
        for(auto& u : um)
        {
            if(u.second > count)
            {
                count = u.second;
                ret = u.first;
            }
        }
        return ret;
    }
};