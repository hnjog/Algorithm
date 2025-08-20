#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    unordered_map<int, int> um;
    
    string it = ""; // 숫자 표현할 요소

    for (char c : s)
    {
        if (c == '{')
        {
            continue;
        }

        if (c == ',' || c == '}')
        {
            if (it == "")
                continue;

            um[stoi(it)]++;
            it = "";
            continue;
        }

        if (c >= '0' && c <= '9')
        {
            it += c;
        }
    }

    vector<pair<int, int>> vec;
    for (auto it : um)
    {
        vec.push_back(it);
    }

    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second > b.second;
        });

    for (const pair<int, int>& it : vec)
    {
        answer.push_back(it.first);
    }

    return answer;
}