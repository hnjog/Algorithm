#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    const int pizzaCount = 7;
    
    
    answer = (n -1) / pizzaCount + 1;
    
    return answer;
}