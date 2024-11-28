#include <string>
#include <vector>
#include <math.h>

using namespace std;

const int winArr[8][3]
=
{
    {0,1,2},
    {3,4,5},
    {6,7,8},
    {0,3,6},
    {1,4,7},
    {2,5,8},
    {0,4,8},
    {2,4,6},
};

bool isWin(const string& board, char c)
{
    // 8 번 체크
    for (int i = 0; i < 8; i++)
    {
        bool isWin = true;
        for (int idx : winArr[i])
        {
            if (board[idx] != c)
            {
                isWin = false;
                break;
            }
        }

        if (isWin)
            return true;
    }

    return false;
}

int solution(vector<string> board) {
    int xCount = 0, oCount = 0;
    string temp = "";

    for (string& line : board)
    {
        temp += line;
        for (char c : line)
        {
            if (c == 'X')
                xCount++;
            else if (c == 'O')
                oCount++;
        }
    }

    // 아무도 안둠
    if (xCount == 0 && oCount == 0)
        return 1;

    // 후공이 선공보다 둔 개수가 많다
    if (xCount > oCount)
        return 0;

    // 선공이 후공 보다 2개 이상 둠
    if (oCount - 1 > xCount)
        return 0;

    // 둘 다 승리 조건을 만족하지 않았으면 그냥 진행
    if (xCount <= 2 && oCount <= 2)
        return 1;

    bool isxWin = isWin(temp, 'X');
    bool isoWin = isWin(temp, 'O');
    
    if (isxWin == true && isoWin == true)
        return 0;
    
    if (isoWin == true &&
        xCount == oCount)
        return 0;
    
    if (isxWin == true &&
        xCount != oCount)
        return 0;

    return 1;
}