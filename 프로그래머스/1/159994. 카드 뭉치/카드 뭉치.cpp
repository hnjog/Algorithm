#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    // stack
    stack<string> st1, st2;
    for(int i= cards1.size() - 1; i >= 0;i--)
    {
        st1.push(cards1[i]);
    }
    
    for(int i= cards2.size() - 1; i >= 0;i--)
    {
        st2.push(cards2[i]);
    }
    
    bool isS = true;
    
    for(int i = 0; i < goal.size();i++)
    {
        string g = goal[i];
        
        if(st1.empty() == false && g == st1.top())
        {
            st1.pop();
        }
        else if(st2.empty() == false && g == st2.top())
        {
            st2.pop();
        }
        else
        {
            isS = false;
            break;
        }
    }
    
    if(isS)
        return "Yes";
    
    return "No";
}