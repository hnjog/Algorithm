#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string temp = "";
    for(int i = my_string.size() - 1; i >=0;i--)
    {
        temp += my_string[i];
        string t = temp;
        reverse(t.begin(),t.end());
        answer.push_back(t);
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}