#include <string>
#include <vector>
#include <math.h>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size;j++)
        {
            if(board[i][j] == 1)
            {
                for(int k = -1; k <= 1; k++)
                {
                    for(int q = -1; q <= 1; q++)
                    {
                        if(k == 0 && q == 0)
                            continue;
                        
                        int x = max(i + k, 0);
                        int y = max(j + q, 0);
                        
                        x = min(x,size - 1);
                        y = min(y,size - 1);
                        
                        if(board[x][y] != 1)
                            board[x][y] = 2;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < size;i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(board[i][j] == 0)
                answer++;
        }
    }
    
    return answer;
}