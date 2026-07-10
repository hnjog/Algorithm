class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> output;
        vector<int> now;

        int idx = 0;

        for (int i = 1; i <= n; i++)
        {
            if (idx >= target.size())
                break;

            if (now.empty() ||
                now.size() <= idx)
            {
                now.push_back(i);
                output.push_back("Push");
                continue;
            }

            if (now[idx] != target[idx])
            {
                now.pop_back();
                output.push_back("Pop");
            }
            else
            {
                idx++;
            }
            i--;
        }

        return output;
    }
};