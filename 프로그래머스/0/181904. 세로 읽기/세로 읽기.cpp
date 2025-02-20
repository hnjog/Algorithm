#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    int idx = 0;
    for(char ch : my_string)
    {
        idx++;
        
        if(idx == c)
            answer += ch;
        
        if(idx >= m)
            idx = 0;
    }
    
    return answer;
}