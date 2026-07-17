class Solution {
public:
    bool isPalindrome(int x) {
        string xstr = to_string(x);
        int n = xstr.size();
        for(int i=0; i < n/2; i++)
        {
            if(xstr[i] != xstr[n-i-1])
                return false;
        }

        return true;
    }
};