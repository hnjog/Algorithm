#include <map>
#include <vector>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    map<string,int> sm;
    string temp = "";
    for(char c : myString)
    {
        if(c == 'x')
        {
            if(temp.size() > 0)
            {
                sm[temp]++;
            }
            temp = "";
        }
        else
        {
            temp += c;
        }
    }
    
    if(temp.size() > 0)
    {
        sm[temp]++;
    }
    
    for(auto& s : sm)
    {
        for(int i= 0; i < s.second;i++)
            answer.push_back(s.first);
    }
    
    
    return answer;
}