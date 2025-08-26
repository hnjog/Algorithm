#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pii> q;
    
    for(int i = 0; i < priorities.size();i++)
    {
        q.push({priorities[i],i});
    }
    
    sort(priorities.begin(),priorities.end(),greater<int>());
    int pIdx = 0;
    
    while(q.empty() == false)
    {
        auto p = q.front();
        q.pop();
        
        if(p.first == priorities[pIdx])
        {
            pIdx++;
            
            if(p.second == location)
                break;
            
            answer++;
            
        }
        else
        {
            q.push(p);
        }
    }
    
    
    return answer;
}