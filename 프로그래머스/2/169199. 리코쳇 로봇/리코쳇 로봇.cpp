#include <string>
#include <vector>
#include<queue>
#include<limits.h>

using namespace std;

    enum dir
    {
        left = 0,
        up,
        right,
        down
    };

    struct wayInfo
    {
        int y = 0;
        int x = 0;
        dir d = left;
        int cost = 0;
    };

int solution(vector<string> board) {


    int answer = -1;
    queue<wayInfo> q;
    
    const int bSize = board.size();
    const int sSize = board[0].size();

    int startY = 0;
    int startX = 0;
    int goalY = 0;
    int goalX = 0;

    for (int i = 0; i < bSize; i++)
    {
        for (int j = 0; j < sSize; j++)
        {
            if (board[i][j] == 'R')
            {
                startY = i;
                startX = j;
            }

            if (board[i][j] == 'G')
            {
                goalY = i;
                goalX = j;
            }
        }
    }
    
    vector<vector< int>> dp1(bSize, vector<int>(sSize, INT_MAX)); // 가로 방향
    vector<vector< int>> dp2(dp1); // 세로 방향

    q.push({ startY,startX,left,0 });
    q.push({ startY,startX,right,0 });
    q.push({ startY,startX,up,0 });
    q.push({ startY,startX,down,0 });

    while (q.empty() == false)
    {
        auto way = q.front();
        q.pop();

        if (way.x == goalX && way.y == goalY)
        {
            answer = way.cost;
            break;
        }

        if (way.d == left || way.d == right)
        {
            if (dp1[way.y][way.x] < way.cost)
                continue;

            dp1[way.y][way.x] = way.cost;
        }
        else
        {
            if (dp2[way.y][way.x] < way.cost)
                continue;

            dp2[way.y][way.x] = way.cost;
        }

        switch (way.d)
        {
        case left:
        {
            int nextX = way.x;
            while(true)
            {
                nextX--;
                if (nextX < 0)
                {
                    nextX = 0;
                    break;
                }

                if (board[way.y][nextX] == 'D')
                {
                    nextX++;
                    break;
                }
            }

            q.push({ way.y,nextX,up,way.cost + 1 });
            q.push({ way.y,nextX,down,way.cost + 1 });
        }
        break;
        case right:
        {
            int nextX = way.x;
            while (true)
            {
                nextX++;
                if (nextX >= sSize)
                {
                    nextX = sSize - 1;
                    break;
                }

                if (board[way.y][nextX] == 'D')
                {
                    nextX--;
                    break;
                }
            }

            q.push({ way.y,nextX,up,way.cost + 1 });
            q.push({ way.y,nextX,down,way.cost + 1 });
        }
        break;

        case up:
        {
            int nextY = way.y;
            while (true)
            {
                nextY++;
                if (nextY >= bSize)
                {
                    nextY = bSize - 1;
                    break;
                }

                if (board[nextY][way.x] == 'D')
                {
                    nextY--;
                    break;
                }
            }

            q.push({ nextY,way.x,left,way.cost + 1 });
            q.push({ nextY,way.x,right,way.cost + 1 });
        }
        break;

        case down:
        {
            int nextY = way.y;
            while (true)
            {
                nextY--;
                if (nextY < 0)
                {
                    nextY = 0;
                    break;
                }

                if (board[nextY][way.x] == 'D')
                {
                    nextY++;
                    break;
                }
            }

            q.push({ nextY,way.x,left,way.cost + 1 });
            q.push({ nextY,way.x,right,way.cost + 1 });
        }
        break;
        }

    }

    return answer;
}