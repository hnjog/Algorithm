#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    int m = 1;
    
    for(int i = 1; i <= n;i++)
    {
        m *= i;
        if(m > n)
        {
            answer = i - 1;
            break;
        }
        else if(m == n)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}