#include<algorithm>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    int idx = 1;
    while(idx < b)
    {
        idx *= 10;
    }
    
    answer = a * idx + b;
    
    int t1 = 2 * a * b;
    answer = max(answer,t1);
    
    return answer;
}