#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int index = 1;
    while(true)
    {
        answer += n % (index * 10) / index;
        
        index *= 10;
        if(index > n)
        {
            break;
        }
    }
    
    return answer;
}