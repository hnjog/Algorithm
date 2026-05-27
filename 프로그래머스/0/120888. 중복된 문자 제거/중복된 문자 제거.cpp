#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string my_string) {
    string answer = "";
    unordered_set<char> s;
    for(int i = 0; i <my_string.size();i++)
    {
        if(s.find(my_string[i]) == s.end())
        {
            s.insert(my_string[i]);
            answer += my_string[i];
        }
    }
    return answer;
}