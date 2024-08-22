#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int maxV = max(a,b);
    int minV = min(a,b);
    
    for(int i = minV; i <= maxV;i++)
        answer += i;
    
    return answer;
}