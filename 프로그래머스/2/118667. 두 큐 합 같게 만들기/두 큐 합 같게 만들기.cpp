#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int n = queue1.size() + queue2.size();
    n *= 2;
    
    queue<int> q1,q2;
    long s1 = 0 , s2 = 0;
    for(int q : queue1)
    {
        q1.push(q);
        s1 += q;
    }
    
    for(int q : queue2)
    {
        q2.push(q);
        s2 += q;
    }
    
    for(int i = 0; i < n;i++)
    {
        if(s1 == s2)
            return i;
        
        if(s1 > s2)
        {
            s2 += q1.front();
            s1 -= q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else
        {
            s1 += q2.front();
            s2 -= q2.front();
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    return -1;
}