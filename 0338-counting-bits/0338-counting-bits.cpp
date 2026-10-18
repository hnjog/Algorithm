class Solution {
    int getCount(int v)
    {
        int c = 0;
        while(v >= 1)
        {
            if(v % 2 == 1)
                c++;
            v /= 2;
        }

        return c;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1);
        for(int i=0;i<=n;i++)
        {
            ret[i] = getCount(i);
        }
        return ret;
    }
};