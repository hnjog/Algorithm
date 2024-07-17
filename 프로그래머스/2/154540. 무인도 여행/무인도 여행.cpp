#include <string>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

void BFS(const vector<string>& maps,int x,int y, vector<vector<bool>>& visited, vector<int>& answer)
{
    queue<pair<int,int>> q;

    q.push({y, x });

    int sum = 0;

    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();

        if (p.first < 0 || p.second < 0 ||
            p.first >= maps.size() || p.second >= maps[0].size())
            continue;

        if (maps[p.first][p.second] == 'X')
            continue;

        if (visited[p.first][p.second])
            continue;

        visited[p.first][p.second] = true;

        sum += static_cast<int>(maps[p.first][p.second] - '0');

        q.push({ p.first - 1,p.second });
        q.push({ p.first + 1,p.second });
        q.push({ p.first,p.second - 1 });
        q.push({ p.first,p.second + 1 });
    }

    answer.push_back(sum);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    // dfs or bfs
    // visited 활용
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (visited[i][j] == true)
                continue;

            if (maps[i][j] == 'X')
                continue;

            BFS(maps, j, i, visited, answer);
        }
    }

    if (answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());

    return answer;
}