#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int pSize = progresses.size();
    vector<pair<int, int>> days;

    for (int i = 0; i < pSize; i++)
    {
        int remain = (100 - progresses[i]);
        int day = remain / speeds[i];
        if (remain % speeds[i] != 0)
        {
            day++;
        }

        if (days.size() == 0)
        {
            days.push_back(make_pair(day, 1));
            continue;
        }

        if (day <= days.back().first)
        {
            days.back().second++;
        }
        else
        {
            days.push_back(make_pair(day, 1));
        }
    }

    for (auto day : days)
    {
        answer.push_back(day.second);
    }

    return answer;
}