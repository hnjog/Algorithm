#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 1;
    
    if(angle == 180)
    {
        answer = 4;
    }
    
    if(angle == 90)
    {
        answer = 2;
    }
    
    if(angle > 90 && angle < 180)
    {
        answer = 3;
    }
    
    return answer;
}