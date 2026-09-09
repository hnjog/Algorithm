class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> vm;
        for(int i=0;i<s.size();i++)
        {
            if(vm.find(s[i]) == vm.end())
            {
                vm[s[i]] = i;
            }
            else
            {
                vm[s[i]] = INT_MAX;
            }
        }

        int ret = INT_MAX;
        for(auto& p : vm)
        {
            ret = min(ret,p.second);
        }

        if(ret == INT_MAX)
            return -1;
        return ret;
    }
};