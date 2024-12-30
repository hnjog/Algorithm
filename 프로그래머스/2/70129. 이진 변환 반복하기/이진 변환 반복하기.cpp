#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void recur(string s, vector<int>& answer, int disZeroCount, int step)
{
    if (s == "1")
    {
        answer.push_back(step);
        answer.push_back(disZeroCount);
        return;
    }

    int tSize = 0;

    for (char c : s)
    {
        if (c == '0')
            disZeroCount++;
        else
            tSize++;
    }

    string t = "";

    while (tSize > 0)
    {
        if (tSize % 2 == 0)
            t += "0";
        else
            t += "1";

        tSize /= 2;
    }

    reverse(t.begin(), t.end());

    recur(t, answer, disZeroCount, step + 1);
}

vector<int> solution(string s) {
    vector<int> answer;
    recur(s, answer, 0, 0);
    return answer;
}