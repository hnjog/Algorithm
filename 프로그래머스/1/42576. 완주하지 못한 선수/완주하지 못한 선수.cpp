#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string,int> m;
    m.reserve(participant.size());
    
    for(string& str : participant)
    {
        m[str]++;
    }
    
    for(string& str : completion)
    {
        m[str]--;
    }
    
    for(auto& p : m)
    {
        if(p.second != 0)
        {
            answer = p.first;
            break;
        }
    }
    
    return answer;
}