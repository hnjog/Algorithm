#include <string>
#include <vector>

using namespace std;

string solution(string n_str) {
    string answer = "";
    bool check = true;
    for(char c : n_str)
    {
        if(check == true && c == '0')
            continue;
        
        answer += c;
        check = false;
    }
    return answer;
}