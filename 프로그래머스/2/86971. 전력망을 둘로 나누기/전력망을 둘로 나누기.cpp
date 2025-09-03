#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

int dfs(unordered_map<int, vector<int>>& maps, vector<bool>& visit, int now,int notVisit)
{
    if (now == notVisit)
        return 0;

    if (visit[now])
        return 0;

    visit[now] = true;

    int ret = 1;
    for (int next : maps[now])
    {
        ret += dfs(maps, visit, next, notVisit);
    }

    return ret;
}

int GetNodeCount(int n,unordered_map<int, vector<int>>& maps, int start, int notVisit)
{
    vector<bool> visit(n + 1);
    return dfs(maps, visit, start, notVisit);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    // 그냥 wire 마다 짜르고
    // 짜른 부위마다 dfs 돌려서
    // 나온 개수 1 - 나온 개수 2 절댓값 구하기

    unordered_map<int, vector<int>> maps;

    for (auto& wire : wires)
    {
        int s = wire[0];
        int t = wire[1];

        maps[s].push_back(t);
        maps[t].push_back(s);
    }

    for (auto& wire : wires)
    {
        int v1 = GetNodeCount(n, maps, wire[0], wire[1]);
        int v2 = GetNodeCount(n, maps, wire[1], wire[0]);

        if (v2 > v1)
            swap(v1, v2);

        if (answer > v1 - v2)
            answer = v1 - v2;
    }

    return answer;
}