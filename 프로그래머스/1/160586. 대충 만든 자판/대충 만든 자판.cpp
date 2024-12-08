#include <string>
#include <vector>
#include <map>
#include <limits.h>

using namespace std;

int getValue(vector<map<char, int>>& vmap, char target)
{
    bool isFindFalse = true;

    int bestMin = INT_MAX;

    for (auto& m : vmap)
    {
        if (m.find(target) != m.end())
        {
            isFindFalse = false;
            bestMin = min(bestMin, m[target]);
        }
    }

    if (isFindFalse)
        return -1;

    return bestMin;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    vector<map<char, int>> vmap;

    for (string str : keymap)
    {
        vmap.push_back(map<char, int>());
        for (int i = 1; i <= str.size(); i++)
        {
            char c = str[i - 1];

            if (vmap.back().find(c) == vmap.back().end())
            {
                vmap.back()[c] = i;
            }
        }
    }

    for (string str : targets)
    {
        bool isCant = false;
        int temp = 0;

        for (char c : str)
        {
            int v = getValue(vmap, c);
            if (v == -1)
            {
                isCant = true;
                break;
            }
            temp += v;
        }

        if (isCant)
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(temp);
        }
    }

    return answer;
}