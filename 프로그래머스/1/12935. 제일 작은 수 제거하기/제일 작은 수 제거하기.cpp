#include <limits.h>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() == 1)
        return {-1};
    
    int lastValue = INT_MAX;
    
    for(int a : arr)
    {
        if(a < lastValue)
            lastValue = a;
    }
    
    for(int a : arr)
    {
        if(a == lastValue)
            continue;
        
        answer.push_back(a);
    }
    
    
    return answer;
}