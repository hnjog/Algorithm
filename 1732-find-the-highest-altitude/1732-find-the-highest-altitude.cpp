class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int best = 0;

        int now = 0;
        for(int g : gain)
        {
            now += g;
            if(now > best)
                best = now;
        }

        return best;
    }
};