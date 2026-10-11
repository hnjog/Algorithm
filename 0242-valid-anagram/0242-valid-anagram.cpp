class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um1,um2;
        for(char c : s)
        {
            um1[c]++;
        }

        for(char c : t)
        {
            if(um1.find(c) == um1.end())
                return false;
            
            um2[c]++;
            if(um2[c] > um1[c])
                return false;
        }

        for(char c : s)
        {
            if(um2.find(c) == um2.end())
                return false;
            if(um2[c] != um1[c])
                return false;
        }

        return true;
    }
};