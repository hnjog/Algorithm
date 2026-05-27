#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    
    const int lambValue = 12000;
    const int sodaValue = 2000;
    
    int serviceSoda = n / 10;
    
    answer = n * lambValue + (k - serviceSoda) * sodaValue; 
    
    return answer;
}