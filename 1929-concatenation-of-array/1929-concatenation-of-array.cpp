class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> returns = nums;
        for(int n : nums)
            returns.push_back(n);
        return returns;
    }
};