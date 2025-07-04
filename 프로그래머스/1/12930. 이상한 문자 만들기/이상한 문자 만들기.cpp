#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int t = 0;
    for(char c : s)
    {
        if(c == ' ')
        {
            answer += c;
            t = 0;
            continue;
        }
        
        if(t % 2 == 0 &&
          c >= 'a' &&
          c <= 'z')
        {
            answer += (char)((int)c - 32);
        }
        else if(t % 2 == 1 &&
               c >= 'A' &&
               c <= 'Z')
        {
            answer += (char)((int)c + 32);
        }
        else
        {
            answer += c;
        }
        t++;
    }
    return answer;
}