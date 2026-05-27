#include <vector>
#include<unordered_map>
#include<queue>

using namespace std;

void findShortWayValue(unordered_map<int, vector<int>>& maps,const int n,vector<int>& dp, int start, int dest)
{
    queue<pair<int,int>> q;

    q.push({ start,0 });

    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();
        int now = p.first;
        int nowCost = p.second;

        for (const auto& nexts : maps[now])
        {
            if (dp[nexts] == -1)
            {
                int nextValue = nowCost + 1;
                dp[nexts] = nextValue;
                q.push({ nexts,nextValue });
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<int> answer;
    unordered_map<int, vector<int>> maps;

    for (auto& road : roads)
    {
        int start = road[0];
        int to = road[1];

        if (maps.find(start) == maps.end())
        {
            maps[start] = vector<int>();
        }

        maps[start].push_back(to);

        if (maps.find(to) == maps.end())
        {
            maps[to] = vector<int>();
        }

        maps[to].push_back(start);
    }

    vector<int> dp(n + 1, -1);
    dp[destination] = 0;

    findShortWayValue(maps, n, dp, destination, 1);

    for (int s : sources)
    {
        answer.push_back(dp[s]);
    }

    return answer;
}