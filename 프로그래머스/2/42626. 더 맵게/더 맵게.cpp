#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1;
    priority_queue<int,vector<int>,greater<int>> que;
    
    int sSize = scoville.size();
    
    for(int i = 0; i < sSize;i++)
    {
        que.push(scoville[i]);
    }
    
    if(que.top() >= K)
        return 0;
    
    int count = 1;
    
    while(que.size() > 1)
    {
        int s1 = que.top();
        que.pop();
        int s2 = que.top();
        que.pop();
        
        int newValue = s1 + s2 * 2;
        que.push(newValue);
        
        if(que.top() >= K)
        {
            answer = count;
            break;
        }
        
        count++;
    }
    
    return answer;
}