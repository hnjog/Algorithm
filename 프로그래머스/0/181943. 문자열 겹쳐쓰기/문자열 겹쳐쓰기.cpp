#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = my_string;
    for(int i = s, j = 0; i < overwrite_string.size(), j < overwrite_string.size();i++, j++)
    {
        answer[i] = overwrite_string[j];
    }
    
    return answer;
}