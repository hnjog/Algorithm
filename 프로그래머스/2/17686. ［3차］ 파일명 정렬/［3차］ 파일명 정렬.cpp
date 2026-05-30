#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> DivideStr(const string& str)
{
    vector<string> ret(3,"");

    int idx = 0;
    int n = str.size();
    for (; idx < n; idx++)
    {
        char c = str[idx];
        if (isdigit(c))
        {
            break;
        }

        ret[0].push_back(c);
    }

    for (; idx < n; idx++)
    {
        char c = str[idx];
        if (isdigit(c) == false)
        {
            break;
        }

        ret[1].push_back(c);
    }

    for (; idx < n; idx++)
    {
        ret[2].push_back(str[idx]);
    }

    return ret;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    answer.reserve(files.size());
    vector<vector<string>> fileDivide;
    fileDivide.reserve(files.size());
    for (const string& str : files)
    {
        fileDivide.emplace_back(DivideStr(str));
    }

    stable_sort(fileDivide.begin(), fileDivide.end(), []
    (auto& a, auto& b)
        {
            string ah = a[0];
            for (char& c : ah)
            {
                c = toupper(c);
            }

            string bh = b[0];
            for (char& c : bh)
            {
                c = toupper(c);
            }

            if (ah != bh)
            {
                return ah < bh;
            }

            int av = stoi(a[1]);
            int bv = stoi(b[1]);

            return av < bv;
        });

    for (auto& str : fileDivide)
    {
        answer.emplace_back(str[0] + str[1] + str[2]);
    }

    return answer;
}