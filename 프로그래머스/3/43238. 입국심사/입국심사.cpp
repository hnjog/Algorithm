#include <vector>
#include <limits.h>

using namespace std;

bool IsCanProcess(long long time, int n, vector<int>& times)
{
    long long remain = n;

    for (int t : times)
    {
        remain -= (time / (long)t);
        if (remain <= 0)
            break;
    }

    return remain <= 0;
}

long long solution(int n, vector<int> times) {
    long long start = 1, end = LONG_MAX / 2;

    while (start < end)
    {
        long long mid = (start + end) / 2;

        if (IsCanProcess(mid, n, times))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return end;
}