#include <vector>

using namespace std;

void hanoi(int start, int to, int via,int n, vector<vector<int>>& answer)
{
    if (n <= 0)
        return;

    hanoi(start, via, to, n - 1, answer);
    answer.push_back({ start,to });
    hanoi(via, to, start, n - 1, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(1, 3, 2, n, answer);

    return answer;
}