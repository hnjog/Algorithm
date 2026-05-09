#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <math.h>

using namespace std;

typedef pair<int, int> pii;

void dfs(int n,unordered_map<int, vector<pii>>& maps, unordered_set<int>& visit, int k, int nowCount,int type, int& answer)
{
    answer = max(int(visit.size()), answer);

    if (nowCount > k ||
        visit.size() == n)
    {
        return;
    }

    vector<int> vec;

    for (int now : visit)
    {
        for (auto& pv : maps[now])
        {
            if (pv.second == type &&
                visit.find(pv.first) == visit.end())
            {
                vec.push_back(pv.first);
            }
        }
    }

    for (int v : vec)
    {
        visit.insert(v);
    }

    if (type == 1)
    {
        if(vec.size() != 0)
            dfs(n, maps, visit, k, nowCount, 1, answer);

        dfs(n, maps, visit, k, nowCount + 1, 2, answer);
        dfs(n, maps, visit, k, nowCount + 1, 3, answer);
    }
    else if (type == 2)
    {
        dfs(n, maps, visit, k, nowCount + 1, 1, answer);

        if (vec.size() != 0)
            dfs(n, maps, visit, k, nowCount, 2, answer);

        dfs(n, maps, visit, k, nowCount + 1, 3, answer);
    }
    else
    {
        dfs(n, maps, visit, k, nowCount + 1, 1, answer);
        dfs(n, maps, visit, k, nowCount + 1, 2, answer);

        if (vec.size() != 0)
            dfs(n, maps, visit, k, nowCount, 3, answer);
    }

    for (int v : vec)
    {
        visit.erase(v);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 1;

    unordered_map<int, vector<pii>> maps;

    for (vector<int>& e : edges)
    {
        int start = e[0];
        int end = e[1];
        int type = e[2];

        maps[start].push_back({ end,type });
        maps[end].push_back({ start,type });
    }
    unordered_set<int> visit;
    visit.insert(infection);
    dfs(n, maps, visit, k, 1, 1, answer);
    visit.clear();
    visit.insert(infection);
    dfs(n, maps, visit, k, 1, 2, answer);
    visit.clear();
    visit.insert(infection);
    dfs(n, maps, visit, k, 1, 3, answer);

    return answer;
}