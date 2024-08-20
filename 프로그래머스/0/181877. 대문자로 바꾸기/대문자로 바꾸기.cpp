#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for(char a : myString)
    {
        if(a >= 'a' && a <= 'z')
        {
            answer += ('A' + a - 'a');
        }
        else
        {
            answer += a;
        }
    }
    return answer;
}