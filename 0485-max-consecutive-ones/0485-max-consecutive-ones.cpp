class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int best = 0;
        for(int n : nums)
        {
            if(n == 1)
            {
                count++;
                if(count > best)
                    best = count;
            }
            else
            {
                count =0;
            }
        }

        return best;
    }
};