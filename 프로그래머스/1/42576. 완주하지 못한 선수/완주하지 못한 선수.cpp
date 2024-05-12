#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> m;
    
    for(int i = 0;i<participant.size();i++)
    {
        if(m.find(participant[i]) == m.end())
        {
            m[participant[i]] = 1;
        }
        else
        {
            m[participant[i]] += 1;
        }
    }
    
    for(int i = 0; i < completion.size();i++)
    {
        if(m.find(completion[i]) != m.end())
        {
            m[completion[i]] -= 1;
        }
    }
    
    for(auto a : m)
    {
        if(a.second != 0)
        {
            answer = a.first;
        }
    }
    
    return answer;
}