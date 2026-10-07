class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(int n : nums)
        {
            if(us.find(n) != us.end())
                return true;
            us.insert(n);
        }
        return false;
    }
};