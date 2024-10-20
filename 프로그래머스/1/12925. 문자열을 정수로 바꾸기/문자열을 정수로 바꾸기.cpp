#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    if(s[0] == '+')
    {
        string temp(s.begin() + 1, s.end());
        answer = stoi(temp);
    }
    else if(s[0] == '-')
    {
        string temp(s.begin() + 1, s.end());
        answer = stoi(temp) * -1;
    }
    else
    {
        answer = stoi(s);
    }
    
    return answer;
}