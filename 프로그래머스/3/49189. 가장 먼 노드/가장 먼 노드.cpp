#include <string>
#include <vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<limits.h>

using namespace std;
typedef pair<int, int> pii;

int solution(int n, vector<vector<int>> edge) {
    unordered_map<int, vector<int>> edgeMap;
    for (const auto& e : edge)
    {
        int begin = e[0];
        int to = e[1];

        if (edgeMap.find(begin) == edgeMap.end())
        {
            edgeMap[begin] = vector<int>();
        }

        edgeMap[begin].push_back(to);

        if (edgeMap.find(to) == edgeMap.end())
        {
            edgeMap[to] = vector<int>();
        }

        edgeMap[to].push_back(begin);
    }

    int answer = 0;
    const int c_start = 1;

    // 각 노드의 코스트 값
    // 이거랑 비교하여 더 작은 쪽을 넣어주며
    // 현재 탐색중인 방식에서 nodeCosts에 기존에 있는 값이랑 비교하여
    // 더 높은 경우는 바로 종료시키기
    vector<int> nodeCosts(n, INT_MAX);
    vector<bool> visited(n, false);

    queue<pii> q;
    q.push(make_pair(c_start, 0));

    while (q.empty() == false)
    {
        auto& e = q.front();
        
        int now = e.first;
        int nowCost = e.second;
        
        q.pop();

        if (visited[now - 1])
        {
            continue;
        }

        // 저장된 코스트 값보다 현재 코스트가 더 크다
        if (nodeCosts[now - 1] < nowCost)
        {
            continue;
        }

        nodeCosts[now - 1] = nowCost;
        visited[now - 1] = true;

        for (int nowE : edgeMap[now])
        {
            q.push(make_pair(nowE, nowCost + 1));
        }
    }

    int answerValue = nodeCosts[0];

    for (int i = 1; i < n; i++)
    {
        if (nodeCosts[i] > answerValue)
        {
            answerValue = nodeCosts[i];
            answer = 1;
        }
        else if (nodeCosts[i] == answerValue)
        {
            answer++;
        }
    }

    return answer;
}
