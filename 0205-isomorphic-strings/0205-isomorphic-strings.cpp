class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> um1,um2;
        if(s.size() != t.size())
            return false;

        for(int i=0;i< s.size();i++)
        {
            char ss = s[i];
            char ts = t[i];

            if(um1.find(ss) == um1.end())
            {
                um1[ss] = ts;
            }
            else
            {
                if(um1[ss] != ts)
                    return false;
            }

            if(um2.find(ts) == um2.end())
            {
                um2[ts] = ss;
            }
            else
            {
                if(um2[ts] != ss)
                    return false;
            }

        }

        return true;
    }
};