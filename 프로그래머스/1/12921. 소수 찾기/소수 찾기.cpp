#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool isPrime(int n)
{
    if(n <= 1)
        return false;
    
    int hn = sqrt(n);
        
    for(int i = 2; i <= hn;i++)
    {
        if(n % i == 0)
            return false;
    }
    
    return true;
}

int solution(int n) {
    if(n <= 1)
        return 0;
    
    int count = 0;
    
    for(int i = 2; i <=n;i++)
    {
        if(isPrime(i))
            count++;
    }
    
    return count;
}