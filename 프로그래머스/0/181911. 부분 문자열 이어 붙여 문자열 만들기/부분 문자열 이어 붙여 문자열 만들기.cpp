#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    for(int i = 0; i < parts.size();i++)
    {
        vector<int>& v = parts[i];
        string temp = "";
        for(int j = v[0]; j <= v[1];j++)
        {
            temp += my_strings[i][j];
        }
        
        answer += temp;
    }
    return answer;
}