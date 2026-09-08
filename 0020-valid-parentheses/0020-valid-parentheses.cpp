class Solution {
public:
    bool isValid(string s) {
        vector<char> cv;

        for(char c : s)
        {
            if(c == '{'||
               c == '('||
               c == '[')
               {
                cv.push_back(c);
               }
               else
               {
                if(cv.empty())
                    return false;
                
                if((c == '}' && cv.back() != '{') ||
                (c == ']' && cv.back() != '[') ||
                (c == ')' && cv.back() != '('))
                    return false;
                
                cv.pop_back();
               }
        }

        return cv.empty();
    }
};