#include <queue>
#include <vector>

using namespace std;

struct infos
{
    int startTime;
    int amount;
};

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<infos> q;
    int pSize = players.size();
    int nowServer = 1;
    for (int i = 0; i < 24; i++)
    {
        while (q.empty() == false)
        {
            auto& info = q.front();
            if (info.startTime <= i)
            {
                int tempA = info.amount;
                nowServer -= tempA;
                q.pop();
            }
            else
            {
                break;
            }
        }
        
        int nowP = players[i];
        if (nowP >= nowServer * m)
        {
            nowP -= nowServer * m;
            int tempA = ((nowP / m) + 1);
            nowServer += tempA;
            answer += tempA;
            q.push({ i + k,tempA });
        }

        
    }

    return answer;
}