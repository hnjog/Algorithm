#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string s) {
    string answer = "";
    map<char,int> m;
    
    for(int i = 0; i < s.size();i++)
    {
        if(m.find(s[i]) != m.end())
        {
            m[s[i]] +=1;
        }
        else
        {
            m[s[i]] = 1;
        }
    }
    
    for(auto p : m)
    {
        if(p.second == 1)
        {
            answer += p.first;
        }
    }
    
    return answer;
}