class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec(numRows, vector<int>());

        for (int i = 0; i < numRows; i++)
        {
            if (i == 0)
            {
                vec[i].push_back(1);
                continue;
            }

            if (vec[i - 1].size() <= 1)
            {
                vec[i].push_back(vec[i - 1][0]);
                vec[i].push_back(vec[i - 1][0]);
                continue;
            }

            vec[i].push_back(vec[i - 1][0]);
            for (int j = 0; j < vec[i-1].size() - 1; j++)
            {
                vec[i].push_back(vec[i - 1][j] + vec[i - 1][j + 1]);
            }
            vec[i].push_back(vec[i - 1][0]);
        }

        return vec;
    }
};
