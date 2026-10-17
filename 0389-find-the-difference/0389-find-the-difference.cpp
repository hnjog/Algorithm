class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> cs;
        for(char c : s)
            cs[c]++;
        
        char ret;

        for(char c : t)
        {
            if(cs.find(c) == cs.end())
            {
                ret = c;
                break;
            }
            
            cs[c]--;
            if(cs[c] == 0)
                cs.erase(c);
        }

        return ret;
    }
};