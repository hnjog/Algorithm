#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    const int sSize = skill.size();
    const int height = board.size();
    const int width = board[0].size();

    int answer = 0;
    // 2차원 누적합?
    // s[i][j] = s[0][0] + s[0][1] + s[1][0] ...
    // 특정 지점에
    vector<vector<int>> boardSum(height + 1, vector<int>(width + 1,0));

    for (int s = 0; s < sSize; s++)
    {
        const int type = skill[s][0];
        const int r1 = skill[s][1];
        const int c1 = skill[s][2];
        const int r2 = skill[s][3];
        const int c2 = skill[s][4];
        const int deg = (type == 1) ? skill[s][5] * -1 : skill[s][5];

        boardSum[r1][c1] += deg;
        boardSum[r2 + 1][c2 + 1] += deg;
        boardSum[r1][c2 + 1] -= deg;
        boardSum[r2 + 1][c1] -= deg;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            boardSum[i][j + 1] += boardSum[i][j];
        }
    }

    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {
            boardSum[i + 1][j] += boardSum[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j] + boardSum[i][j] > 0)
                answer++;
        }
    }

    return answer;
}