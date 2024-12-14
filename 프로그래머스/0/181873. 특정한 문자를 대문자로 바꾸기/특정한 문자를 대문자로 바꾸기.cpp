#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    for(char c : my_string)
    {
        if(c == alp[0])
            c = toupper(c);
        
        answer += c;
    }
    return answer;
}