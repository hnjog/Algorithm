class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n,0);
        vector<pair<int,int>> stacks;
        
        for (string& log : logs)
        {
            int p1 = log.find(':');
            int p2 = log.find(':', p1 + 1);

            int id = stoi(log.substr(0,p1));
            char c = log[p1 + 1];
            int time = stoi(log.substr(p2 + 1, log.size()));

            if (c == 's')
            {
                if (stacks.empty())
                    stacks.push_back({ id,time });
                else
                {
                    ret[stacks.back().first] += (time - stacks.back().second);
                    stacks.back().second = time;
                    stacks.push_back({ id,time });
                }
            }
            else
            {
                if (stacks.empty() == false)
                {
                    ret[stacks.back().first] += (time - stacks.back().second + 1);
                    stacks.pop_back();

                    if (stacks.empty() == false)
                        stacks.back().second = time + 1;
                }
            }
        }

        return ret;
    }
};