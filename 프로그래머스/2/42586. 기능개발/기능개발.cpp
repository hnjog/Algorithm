#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day = 1;
    int pIdx = 0;
    
    while(pIdx < progresses.size())
    {
        int result = 0;
        while(pIdx < progresses.size() &&
            progresses[pIdx] + speeds[pIdx] * day >= 100)
        {
            result++;
            pIdx++;
        }
        
        if(result != 0)
        {
            answer.push_back(result);
        }
        
        day++;
    }
    
    
    return answer;
}