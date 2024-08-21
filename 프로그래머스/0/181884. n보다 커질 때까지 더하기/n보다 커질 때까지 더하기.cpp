#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    for(auto num : numbers)
    {
        answer += num;
        if(answer > n)
            break;
    }
    return answer;
}