class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        int idx = 0;
        while(true)
        {
            bool bEnd = false;
            char now = ' ';
            for(string& str : strs)
            {
                if(idx >= str.size())
                {
                    bEnd = true;
                    break;
                }

                if(now == ' ')
                {
                    now = str[idx];
                }
                else if(now != str[idx])
                {
                    bEnd = true;
                    break;
                }
            }
            if(bEnd)
                break;
            
            ret += now;
            idx++;
        }

        return ret;
    }
};