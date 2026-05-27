#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool CanTrans(const string& a, const string& b)
{
    if (a.size() != b.size())
        return false;

    int changeCount = 0;

    int ss = a.size();
    for (int i = 0; i < ss; i++)
    {
        if (a[i] != b[i])
            changeCount++;

        if (changeCount > 1)
            return false;
    }

    if (changeCount == 1)
        return true;

    return false;
}

struct infos
{
    string str;
    int cost;
};

int solution(string begin, string target, vector<string> words) {
    queue<infos> q;
    unordered_set<string> visit;

    q.push({ begin,0 });

    while (q.empty() == false)
    {
        string now = q.front().str;
        int nowcost = q.front().cost;
        q.pop();

        if (now == target)
        {
            return nowcost;
        }

        if (visit.find(now) != visit.end())
            continue;

        visit.insert(now);

        for (const string& word : words)
        {
            if (CanTrans(now, word))
            {
                q.push({ word,nowcost + 1 });
            }
        }
    }

    return 0;
}