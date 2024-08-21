#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(auto c : myString)
    {
        if(c >= 'A' && c <= 'Z')
        {
            answer += ('a' + c - 'A');
        }
        else
        {
            answer += c;
        }
    }
    return answer;
}