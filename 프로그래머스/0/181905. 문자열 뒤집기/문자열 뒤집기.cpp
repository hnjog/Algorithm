#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    string temp = "";
    bool rEnd = false;
    for(int i = 0; i <my_string.size();i++)
    {
        char c = my_string[i];
        
        if(i >= s && i <= e && rEnd == false)
        {
            temp += c;
            if(i == e)
            {
                for(int j = temp.size() - 1; j >= 0; j--)
                    answer += temp[j];
                rEnd = true;
            }
        }
        else
        {
            answer += c;
        }
            
    }
    return answer;
}