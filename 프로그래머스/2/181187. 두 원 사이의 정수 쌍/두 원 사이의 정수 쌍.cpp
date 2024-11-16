#include<math.h>

using namespace std;


long long solution(int r1, int r2) {
    long long answer = 0;

    for (long long x = 1; x < r2; x++)
    {
        double y2 = sqrt((long long)r2 * r2 - x * x);
        double y1 = sqrt((long long)r1 * r1 - x * x);

        answer += ((long long)y2 - (long long)ceil(y1) + 1);
    }

    answer++;
    answer *= 4;

    return answer;
}