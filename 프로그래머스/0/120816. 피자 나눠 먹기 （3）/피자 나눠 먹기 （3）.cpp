#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 1;
	const int pizzaCount = slice;

    while(n > slice)
    {
        answer++;
        n -= slice;
    }
    
    return answer;
}