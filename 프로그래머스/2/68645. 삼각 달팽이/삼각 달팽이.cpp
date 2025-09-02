#include <vector>

using namespace std;

const int dirY[3] = {1,0,-1};
const int dirX[3] = {0,1,-1};

vector<int> solution(int n) 
{
    vector<int> answer;
    
    int count = 0;
    for(int i =0;i<=n;i++)
        count +=i;
    
    vector<vector<int>> maps(n,vector<int>(n,0));
    
    int y = 0;
    int x = 0;
    int dir = 0;
    int value = 0;
    
    while(true)
    {
        value++;
        maps[y][x] = value;
        if(value >= count)
            break;
        
        int nextY = y + dirY[dir];
        int nextX = x + dirX[dir];
        
        if(nextY < 0 || nextX < 0 ||
          nextY >= n || nextX >= n ||
          maps[nextY][nextX] != 0)
        {
            dir = (dir + 1) % 3;
            nextY = y + dirY[dir];
            nextX = x + dirX[dir];
        }
        
        y = nextY;
        x = nextX;
    }
    
    for(int i = 0; i < n;i++)
        for(int j = 0; j <=i;j++)
            answer.push_back(maps[i][j]);
    
    return answer;
}