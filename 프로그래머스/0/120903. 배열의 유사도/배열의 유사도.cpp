#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    unordered_map<string,int> m;
    
    for(int i = 0; i < s1.size();i++)
    {
        m.insert(make_pair(s1[i],1));
    }
    
    for(int i = 0; i < s2.size();i++)
    {
        if(m.find(s2[i])!= m.end())
        {
            answer++;
        }
    }
    
    return answer;
}