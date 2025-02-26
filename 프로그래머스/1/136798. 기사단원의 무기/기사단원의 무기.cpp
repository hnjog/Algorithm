#include <math.h>
#include <vector>

using namespace std;

int getCount(int n)
{
    if(n <= 1)
        return 1;
    
    int ret = 2; // 1, n
    
    int sq = sqrt(n);
    
    for(int i = 2; i <= sq;i++)
    {
        if(n % i == 0)
        {
            if(i * i == n)
                ret++;
            else
                ret += 2;
        }
    }
    
    return ret;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i<= number;i++)
    {
        int g = getCount(i);
        if(g > limit)
            g = power;
        answer += g;
    }
    
    return answer;
}