class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ret;
        ret.reserve(nums.size());

        unordered_map<int, int> ms;
        for (int n : nums)
        {
            ms[n]++;
        }

        for (int n : nums)
        {
            int s = 0;
            for (int i = 0; i < n; i++)
            {
                if (ms.find(i) != ms.end())
                    s += ms[i];
            }
            ret.push_back(s);
        }

        return ret;
    }
};