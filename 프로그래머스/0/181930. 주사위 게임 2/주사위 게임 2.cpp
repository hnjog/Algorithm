#include <map>
#include <cmath>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    map<int,int> ms;
    ms[a]++;
    ms[b]++;
    ms[c]++;
    
    if(ms.size() == 1)
    {
        answer = pow(a,6) * 27;
    }
    else if(ms.size() == 2)
    {
        answer = (a + b + c) * (a * a + b * b + c * c);
    }
    else
    {
        answer = a + b + c;
    }
    
    return answer;
}