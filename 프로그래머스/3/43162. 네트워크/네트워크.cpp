#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Bfs(unordered_map<int, vector<int>>& maps, vector<int>& parents,int start)
{
    if (parents[start] != start)
        return;

    queue<int> q;
    q.push(start);

    while (q.empty() == false)
    {
        int now = q.front();
        q.pop();

        if (now != start &&
            parents[now] == start)
            continue;

        parents[now] = start;

        for (int next : maps[now])
        {
            q.push(next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    unordered_map<int, vector<int>> maps;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (computers[i][j] == 1)
            {
                maps[i].push_back(j);
            }
        }
    }

    vector<int> parent(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        Bfs(maps, parent, i);
    }

    unordered_set<int> counts;
    
    for (int i = 0; i < n; i++)
    {
        counts.insert(parent[i]);
    }

    return counts.size();
}