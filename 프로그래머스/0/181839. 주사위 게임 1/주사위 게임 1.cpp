#include<math.h>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    bool bAllNot = false;
    
    if(a % 2 == 1)
    {
        if(b % 2 == 1)
        {
            answer = a * a + b * b;
        }
        else
        {
            bAllNot = true;
        }
    }
    else
    {
        if(b % 2 == 0)
        {
            answer = abs(a - b);
        }
        else
        {
            bAllNot = true;
        }
    }
    
    if(bAllNot)
    {
        answer = (a + b) * 2;
    }
    
    
    return answer;
}