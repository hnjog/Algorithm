#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    int maxX = dots[0][0];
    int minX = dots[0][0];
    int maxY = dots[0][1];
    int minY = dots[0][1];
    
    for(int i = 1; i < 4;i++)
    {
        int tempX = dots[i][0];
        int tempY = dots[i][1];
        
        if(tempX > maxX)
            maxX = tempX;
        else if(tempX < minX)
            minX = tempX;
        
        if(tempY > maxY)
            maxY = tempY;
        else if(tempY < minY)
            minY = tempY;
    }
    
    answer = abs(maxX - minX) * abs(maxY - minY);
    
    return answer;
}