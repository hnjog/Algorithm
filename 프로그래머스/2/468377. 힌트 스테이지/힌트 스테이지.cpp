#include <vector>
#include <limits.h>

using namespace std;

void recur(vector<vector<int>>& cost, vector<vector<int>>& hint, vector<int>& hintCounts, int idx, int sum, int& answer)
{
    int n = cost.size();

    if (idx >= n)
    {
        answer = min(sum, answer);
        return;
    }

    int hc = hintCounts[idx];
    if (hc >= cost[idx].size())
        hc = cost[idx].size() - 1;

    sum += cost[idx][hc];

    recur(cost, hint, hintCounts, idx + 1, sum, answer);
    
    if (idx < n - 1)
    {
        sum += hint[idx][0];

        for (int i = 1; i < hint[idx].size(); i++)
        {
            hintCounts[hint[idx][i] - 1]++;
        }

        recur(cost, hint, hintCounts, idx + 1, sum, answer);

        for (int i = 1; i < hint[idx].size(); i++)
        {
            hintCounts[hint[idx][i] - 1]--;
        }

        sum -= hint[idx][0];
    }
}


int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = INT_MAX;
    vector<int> hints(cost.size(), 0);

    recur(cost, hint, hints, 0, 0, answer);

    return answer;
}