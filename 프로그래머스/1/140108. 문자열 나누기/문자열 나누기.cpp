#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int targetCount =0;
    int otherCount = 0;
    char targetC = ' ';
    for(char c : s)
    {
        if(targetCount == 0)
        {
            targetC = c;
        }
        
        if(c == targetC)
        {
            targetCount++;
        }
        else
        {
            otherCount++;
        }
        
        if(targetCount == otherCount)
        {
            answer++;
            targetCount = 0;
            otherCount=0;
        }
    }
    
    if(targetCount > 0)
        answer++;
    
    return answer;
}