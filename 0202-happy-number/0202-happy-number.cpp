class Solution {
    bool check(set<int>& vv, int now)
    {
        if(vv.find(now) != vv.end())
            return false;
        
        if(now == 1)
            return true;
        
        vv.insert(now);

        int next = 0;
        string t = to_string(now);
        for(char c : t)
        {
            int v = c - '0';
            next += v * v;
        }

        return check(vv,next);
    }

public:
    bool isHappy(int n) {
        set<int> v;
        return check(v,n);
    }
};