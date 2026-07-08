class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret;
        int twin = 0;
        int maxV = 0;
        set<int> ns;
        for(int n : nums)
        {
            if(maxV < n)
                maxV = n;

            if(ns.find(n) == ns.end())
            {
                ns.insert(n);
            }
            else
            {
                twin = n;
            }
        }

        ret.push_back(twin);
        int back = maxV;
        for(int i=1;i<=back;i++)
        {
            if(ns.find(i) == ns.end())
            {
                ret.push_back(i);
                break;
            }
        }
        if(ret.size() == 1)
            ret.push_back(back + 1);
        return ret;
    }
};