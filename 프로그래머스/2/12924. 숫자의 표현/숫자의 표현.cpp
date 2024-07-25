#include <vector>

using namespace std;

int solution(int n) {
    
    if (n <= 2)
        return 1;
    
    int answer = 1;

    for (int i = 1; i <= n / 2 + 1; i++)
    {
        int sum = 0;
        for (int j = i; j <= n / 2 + 1; j++)
        {
            sum += j;
            if (sum >= n)
            {
                if (sum == n)
                    answer++;

                break;
            }
        }
    }

    return answer;
}