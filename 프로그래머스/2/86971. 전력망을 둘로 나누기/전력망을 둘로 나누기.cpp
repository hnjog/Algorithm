#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int GetValue(unordered_map<int, vector<int>>& maps, int start, vector<bool>& visit)
{
    int ret = 0;

    queue<int> q;
    q.push(start);

    while (q.empty() == false)
    {
        int n = q.front();
        q.pop();

        if (visit[n] == true &&
            n != start)
        {
            continue;
        }

        visit[n] = true;
        ret++;

        for (int next : maps[n])
        {
            if (visit[next])
                continue;
            q.push(next);
        }

    }

    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    unordered_map<int, vector<int>> maps;

    for (auto& w : wires)
    {
        int start = w[0] - 1;
        int end = w[1] - 1;
        maps[start].push_back(end);
        maps[end].push_back(start);
    }


    for (auto& w : wires)
    {
        vector<bool> visit(n, false);
        int start = w[0] - 1;
        int end = w[1] - 1;
        visit[start] = true;
        visit[end] = true;
        int v1 = GetValue(maps, start, visit);
        int v2 = GetValue(maps, end, visit);
        int vv = v1 - v2 < 0 ? v2 - v1 : v1 - v2;

        if (vv < answer)
            answer = vv;
    }

    return answer;
}