class Solution {
public:
    int mySqrt(int x) {
        int ret = 0;
        for(long i=1;i<=x;i++)
        {
            long vv = i* i;
            if(vv == x)
            {
                ret = i;
                break;
            }
            else if(vv > x)
            {
                ret =i-1;
                break;
            }
        }
        return ret;
    }
};