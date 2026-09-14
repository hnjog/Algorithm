class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp = "";

        bool canReset = false;
        for(char c : s)
        {
            if(c == ' ')
            {
                canReset = true;
                continue;
            }

            if(canReset)
            {
                temp.clear();
            }

            temp.push_back(c);
            canReset = false;
        }

        return temp.size();   
    }
};