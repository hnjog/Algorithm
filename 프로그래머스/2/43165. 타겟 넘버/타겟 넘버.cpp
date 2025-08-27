#include <string>
#include <vector>

using namespace std;

int answer = 0;

void recur(const vector<int>& numbers, const int target, int nowIdx, int nowValue)
{
    int nSize = numbers.size();
    if(nowIdx == nSize)
    {
        if(nowValue == target)
            answer++;
        
        return;
    }
    
    recur(numbers,target,nowIdx + 1,nowValue + numbers[nowIdx]);
    recur(numbers,target,nowIdx + 1,nowValue - numbers[nowIdx]);
}


int solution(vector<int> numbers, int target) {
    recur(numbers,target,0,0);
    return answer;
}