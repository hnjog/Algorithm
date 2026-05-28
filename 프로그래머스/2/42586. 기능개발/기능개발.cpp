#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>> workq;
    
    for(int i=0;i<progresses.size();i++)
    {
        workq.push({100 - progresses[i],speeds[i]});
    }
    
    int day = 0;
    while(workq.empty() == false)
    {
        day++;
        if(workq.front().first <= workq.front().second * day)
        {
            int d = 0;
            while(workq.front().first <= workq.front().second * day &&
                 workq.empty() == false)
            {
                d++;
                workq.pop();
            }
            
            answer.push_back(d);
        }
    }
    
    return answer;
}