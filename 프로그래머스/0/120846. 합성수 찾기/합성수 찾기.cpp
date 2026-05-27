#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool checkMix(int n)
{
    if(n <= 3)
        return false;
    
    int sqr = sqrt(n);
    
    for(int i = 2; i <= sqr;i++)
    {
        if(n%i == 0)
        {
            return true;
        }
    }
    
    return false;
}

int solution(int n) {
    int answer = 0;
    
    for(int i = 4; i <=n;i++)
    {
        if(checkMix(i))
        {
            answer++;
        }
    }
    
    return answer;
}