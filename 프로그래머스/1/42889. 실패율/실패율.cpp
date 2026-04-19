#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef pair<int,float> pif;

struct Compare
{
    bool operator()(const pif& a, const pif& b)
    {
        if(abs(a.second- b.second) < 1e-11)
            return a.first > b.first;
        
        return a.second < b.second;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    answer.reserve(N);
    unordered_map<int,int> sm;
    
    for(int s : stages)
    {
        sm[s]++;
    }
    
    int p = stages.size();
    
    priority_queue<pif,vector<pif>,Compare> pq;
    
    for(int i=1;i<=N;i++)
    {
        float val = (p <= 0) ? 0 : float(sm[i]) / p;
        
        pq.push({i,val});
        
        p -= sm[i];
    }
    
    while(pq.empty() == false)
    {
        answer.push_back(pq.top().first);
        pq.pop();
    }
    
    return answer;
}