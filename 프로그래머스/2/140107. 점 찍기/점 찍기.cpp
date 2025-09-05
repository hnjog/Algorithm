#include <vector>
#include <math.h>

using namespace std;

typedef unsigned long long ull;

long long solution(int k, int d)
{
    long long answer = 0;
    ull ds = d * (ull)d;

    for (ull i = 0; i <= d; i += k)
    {
        ull ys = i * i;
        ull xs = ds - ys;
        ull xs1 = sqrt(xs);
        ull xcount = xs1 / k + 1;
        answer += xcount;
    }

    return answer;
}