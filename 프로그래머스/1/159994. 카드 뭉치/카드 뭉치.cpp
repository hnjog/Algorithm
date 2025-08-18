#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    bool isS = true;
    
    queue<string> s1,s2;
    for(string& s : cards1)
    {
        s1.push(s);
    }
    
    for(string& s : cards2)
    {
        s2.push(s);
    }
    
    for(auto it = goal.begin(); it != goal.end();it++)
    {
        if(s1.empty() == false && (*it) == s1.front())
        {
            s1.pop();
        }
        else if(s2.empty() == false && (*it) == s2.front())
        {
            s2.pop();
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