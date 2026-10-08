class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        
        for(int i =0;i<nums.size();i++)
        {
            int n = nums[i];
            if(um.find(n) != um.end())
            {
                if(i - um[n] <= k)
                    return true;
            }
            um[n] = i;            
        }
        
        return false;
    }
};