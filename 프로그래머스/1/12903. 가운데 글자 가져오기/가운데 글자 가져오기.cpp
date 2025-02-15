#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer;
    if(s.size() % 2 == 0)
    {
        int idx = s.size() / 2 - 1;
        answer += s[idx];
        answer += s[idx + 1];
    }
    else
    {
        int idx = s.size() / 2;
        answer += s[idx];
    }
    return answer;
}