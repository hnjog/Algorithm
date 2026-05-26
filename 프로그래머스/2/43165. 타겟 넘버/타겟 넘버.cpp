#include <vector>

using namespace std;

int Recur(const vector<int>& numbers, int target, int idx, int nowValue)
{
    int ns = numbers.size();
    if (ns == idx)
    {
        if (target == nowValue)
            return 1;

        return 0;
    }

    int ret = 0;
    ret += Recur(numbers, target, idx + 1, nowValue + numbers[idx]);
    ret += Recur(numbers, target, idx + 1, nowValue - numbers[idx]);
    return ret;
}

int solution(vector<int> numbers, int target) {
    return Recur(numbers,target,0,0);
}
