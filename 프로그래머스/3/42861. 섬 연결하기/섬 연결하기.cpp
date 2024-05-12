#include <vector>
#include<queue>
#include<unordered_map>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    unordered_map<int, vector<pair<int, int>>> islandMap;

    int maxIsland = 0;
    for (const auto& c : costs)
    {
        maxIsland = max(maxIsland, max(c[0], c[1]));
        islandMap[c[0]].push_back({ c[1], c[2] });
        islandMap[c[1]].push_back({ c[0], c[2] });
    }

    int totalCosts = 0;

    // Prims
    struct Edge {
        int to, cost;
        Edge(int to, int cost) : to(to), cost(cost) {}
        bool operator>(const Edge& other) const {
            return cost > other.cost;
        }
    };

    priority_queue< Edge,vector<Edge>,greater<Edge>> pq;
    vector<bool> visited(n + 1, false);
    for (const auto& e : islandMap[0])
    {
        pq.push(Edge(e.first, e.second));
    }

    visited[0] = true;

    while (pq.empty() == false)
    {
        auto e = pq.top();
        int next = e.to;
        int cost = e.cost;
        
        pq.pop();

        if (visited[next] == true)
            continue;
        
        visited[next] = true;
        totalCosts += cost;

        for (const auto& p : islandMap[next])
        {
            int pNext = p.first;
            int pCost = p.second;
            if (visited[pNext] == false)
            {
                pq.push(Edge(pNext, pCost));
            }
        }
    }

    return totalCosts;
}