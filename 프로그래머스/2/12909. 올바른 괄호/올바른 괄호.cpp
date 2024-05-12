#include<string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int sSize = s.size();
    
    vector<char> cArr;
    cArr.reserve(sSize);
    bool bStopped = false;
    
    for(int i = 0; i < sSize;i++)
    {
        if(s[i] == '(')
        {
            cArr.push_back(s[i]);
        }
        else
        {
            // 괄호 벡터가 비어있는데 닫는 것부터 나왔다
            if(cArr.size() == 0)
            {
                bStopped = true;
                break;
            }
            
            cArr.pop_back();
        }
    }
    
    if(bStopped || cArr.size() != 0)
    {
        answer = false;
    }

    return answer;
}