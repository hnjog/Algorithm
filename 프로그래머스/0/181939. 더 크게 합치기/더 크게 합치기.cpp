#include <string>
#include <vector>

using namespace std;

int getValue(int a, int b)
{
    int idx = 1;
    
    while(idx <= b)
    {
        idx *= 10;
    }
    
    return a * idx + b;
}

int solution(int a, int b) {
    int answer = max(getValue(a,b),getValue(b,a));
    return answer;
}