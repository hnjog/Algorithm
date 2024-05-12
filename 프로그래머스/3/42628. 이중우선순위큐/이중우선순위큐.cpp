#include <string>
#include <vector>
#include<set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    set<int> m;

    for (const auto& st : operations)
    {
        if (st[0] == 'I')
        {
            string numStr;
            bool isMValue = false;

            for (const auto& c : st)
            {
                if (isdigit(c))
                    numStr.push_back(c);
                else if (c == '-')
                    isMValue = true;
            }

            if (numStr.empty() == false)
            {
                int value = stoi(numStr);
                if (isMValue == true)
                    value *= -1;

                m.insert(value);
            }
        }
        else
        {
            if (m.empty())
                continue;

            if (st[2] == '-')
            {
                m.erase(m.begin());
            }
            else
            {
                auto it = m.end();
                it--;
                m.erase(it);
            }
        }
    }

    if (m.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        auto it = m.end();
        it--;
        answer.push_back(*it);
        it = m.begin();
        answer.push_back(*it);
    }

    return answer;
}