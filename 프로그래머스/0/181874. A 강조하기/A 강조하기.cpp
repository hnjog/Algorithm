#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(char c : myString)
    {
        if(c == 'a')
            c = 'A';
        else if(c <= 'Z' && c >= 'B')
            c = (char)tolower(c);
        
        answer += c;
    }
    return answer;
}