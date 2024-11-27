#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    l--;
    r--;
    for (long long i = l; i <= r; i++)
    {
        // 0 인 경우
        if (i % 5 == 2)
            continue;

        bool checkTwo = false;

        long long tempI = i;
        while (tempI >= 5)
        {
            tempI /= 5;
            if (tempI % 5 == 2)
            {
                checkTwo = true;
                break;
            }
        }

        if (checkTwo == false)
        {
            answer++;
        }
    }

    return answer;
}
