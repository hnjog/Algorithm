#include<string>
#include<vector>
using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<char> cV;
    
    for(char c : s)
    {
        if(cV.empty())
        {
            cV.push_back(c);
        }
        else
        {
            if(c == cV.back())
            {
                cV.pop_back();
            }
            else
            {
                cV.push_back(c);
            }
        }
    }
    
    if(cV.empty())
        answer = 1;

    return answer;
}