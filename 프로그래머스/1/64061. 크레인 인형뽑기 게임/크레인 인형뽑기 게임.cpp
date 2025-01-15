#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<stack<int>> maps(board.size(),stack<int>());
    stack<int> containers;

    for (int i = board.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j])
                maps[j].push(board[i][j]);
        }
    }

    for (int m : moves)
    {
        int target = m - 1;

        if (maps[target].empty())
            continue;

        int doll = maps[target].top();
        maps[target].pop();

        if (containers.empty() == false &&
            containers.top() == doll)
        {
            containers.pop();
            answer += 2;
        }
        else
        {
            containers.push(doll);
        }
    }

    return answer;
}