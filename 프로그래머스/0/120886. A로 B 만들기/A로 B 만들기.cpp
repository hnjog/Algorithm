#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    map<char,int> m;
    
    for(int i = 0; i<before.size();i++)
    {
        if(m.find(before[i]) == m.end())
        {
            m[before[i]] = 1;
        }
        else
        {
            m[before[i]]+= 1;
        }
    }
    
    for(int i = 0; i < after.size();i++)
    {
        if(m.find(after[i]) == m.end())
        {
            return answer;
        }
        
        m[after[i]] -= 1;
    }
    
    for(auto a : m)
    {
        if(a.second != 0)
        {
            return answer;
        }
    }
    
    answer = 1;
    return answer;
}