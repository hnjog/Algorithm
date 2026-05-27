#include <string>
#include <vector>
#include <math.h>
using namespace std;

int isSNum(int num)
{
    int sN = sqrt(num);
    return (num == sN * sN) ? 1 : 2;
}

int solution(int n) {
    int answer = isSNum(n);
    return answer;
}