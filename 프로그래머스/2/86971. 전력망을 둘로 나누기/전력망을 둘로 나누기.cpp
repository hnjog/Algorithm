#include <string>
#include <vector>
#include<math.h>
#include<limits.h>

using namespace std;

vector<int> tree[101];
int subtreeSize[101];
bool visited[101];

int dfs(int node);

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        int u = wires[i][0];
        int v = wires[i][1];
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        int diff = abs(n - 2 * subtreeSize[i]);
        if (diff < answer) {
            answer = diff;
        }
    }

    return answer;
}

int dfs(int node) {
    visited[node] = true;
    subtreeSize[node] = 1; // 현재 노드 포함

    for (int child : tree[node]) {
        if (!visited[child]) {
            subtreeSize[node] += dfs(child);
        }
    }

    return subtreeSize[node];
}