#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

enum nodeStates
{
    odd,
    even,
    rOdd,
    rEven,
};

struct nodeInfo
{
    int nodeNum;
    vector<int> childs;
    nodeStates state;

    nodeStates getState(bool isRoot = false)
    {
        if (isRoot)
            return state;

        switch (state)
        {
        case odd:
            return nodeStates::rOdd;
        case even:
            return nodeStates::rEven;
        case rOdd:
            return nodeStates::odd;
        case rEven:
            return nodeStates::even;
        }

        return state;
    }
};

// 0 : 홀짝 트리, 1 : 역홀짝 트리, -1 : 아무것도 아님
int findTrees(unordered_map<int, nodeInfo>& graphs,int rootNum)
{
    unordered_set<int> visited;
    bool bIsOddTree = false; 

    switch (graphs[rootNum].getState(true))
    {
    case odd:
    case even:
        bIsOddTree = true;
        break;
    default:
        break;
    }

    queue<int> q;
    for (int n : graphs[rootNum].childs)
    {
        q.push(n);
    }

    visited.insert(rootNum);

    while (q.empty() == false)
    {
        nodeInfo& n = graphs[q.front()];
        q.pop();

        if (visited.find(n.nodeNum) != visited.end())
            continue;

        visited.insert(n.nodeNum);

        nodeStates ns = n.getState();
        if ((bIsOddTree && (ns == rOdd || ns == rEven)) ||
            (bIsOddTree == false && (ns == odd || ns == even)))
        return -1;

        for (int nextN : n.childs)
        {
            q.push(nextN);
        }
    }

    if (bIsOddTree)
        return 0;

    return 1;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2,0);
    unordered_map<int, nodeInfo> graphs;

    for (int node : nodes)
    {
        graphs[node].nodeNum = node;
    }

    for (vector<int>& edge : edges)
    {
        int v1 = edge[0];
        int v2 = edge[1];

        graphs[v1].nodeNum = v1;
        graphs[v1].childs.push_back(v2);
        graphs[v2].nodeNum = v2;
        graphs[v2].childs.push_back(v1);
    }

    for (auto& g : graphs)
    {
        nodeInfo& n = g.second;

        if (n.nodeNum % 2 == 1)
        {
            if (n.childs.size() % 2 == 1)
            {
                n.state = nodeStates::odd;
            }
            else
            {
                n.state = nodeStates::rOdd;
            }
        }
        else
        {
            if (n.childs.size() % 2 == 0)
            {
                n.state = nodeStates::even;
            }
            else
            {
                n.state = nodeStates::rEven;
            }
        }
    }

    for (int node : nodes)
    {
        int v = findTrees(graphs, node);
        if (v == 0)
            answer[0]++;
        if (v == 1)
            answer[1]++;

    }

    return answer;
}