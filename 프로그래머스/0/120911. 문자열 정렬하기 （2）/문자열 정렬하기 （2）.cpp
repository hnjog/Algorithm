#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(string my_string) {
    string answer = "";
    map<char,int> m;
    
    for(int i = 0;i < my_string.size();i++)
    {
        char a = my_string[i];
        if(a >= 'A' && a <= 'Z')
        {
            a -= ('A' - 'a');
        }
        
        if(m.find(a) != m.end())
        {
            m[a] += 1;
        }
        else
        {
            m[a] = 1;
        }
    }
    
    for(auto a : m)
    {
        for(int i = 0; i < a.second;i++)
        {
            answer += a.first;
        }
    }
    
    return answer;
}