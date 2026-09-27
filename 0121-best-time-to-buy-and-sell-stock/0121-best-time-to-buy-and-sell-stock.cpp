class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;

        int tv = prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i] < tv)
            {
                tv = prices[i];
            }
            else
            {
                ret = max(ret, prices[i] - tv);
            }
        }

        return ret;
    }
};