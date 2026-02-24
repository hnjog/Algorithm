#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int dirY[4] = {0,-1,0,1};
const int dirX[4] = {-1,0,1,0};

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int mh = board.size();
    int mw = board[0].size();
    
    string nowColor = board[h][w];
    
    for(int i=0;i<4;i++)
    {
        int ny = h + dirY[i];
        int nx = w + dirX[i];
        
        if(ny < 0 || ny >= mh||
          nx < 0 || nx >= mw)
            continue;
        
        if(board[ny][nx] == nowColor)
            answer++;
    }
    
    return answer;
}