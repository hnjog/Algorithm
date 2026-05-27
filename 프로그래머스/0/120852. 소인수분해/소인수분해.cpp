#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool isPriority(int n)
{
    if(n <= 1)
    {
        return false;
    }
    else if(n <= 3)
    {
        return true;
    }
    int sN = sqrt(n);
    
    for(int i = 2; i <= sN;i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    
    return true;
}

vector<int> solution(int n) {
    vector<int> answer;
    
    if(isPriority(n))
    {
        answer.push_back(n);
    }
    else
    {
        for(int i = 2; i <=n;i++)
        {
            if(n%i == 0 &&
              isPriority(i))
            {
                answer.push_back(i);
            }
        }    
    }    
    
    return answer;
}