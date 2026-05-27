#include <string>
#include <vector>
#include<math.h>

using namespace std;

int solution(int n) {
    if (n == 1)
{
    return 1;
}
    int answer = 2;

    int q = sqrt(n);
    
    for (int i = 2; i <= q; i++)
    {
        int m = n % i;
        if (m == 0)
        {
            if (n / i == i)
            {
                answer += 1;
            }
            else 
            {
                answer += 2;
            }
        }
    }

    return answer;
}