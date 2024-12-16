#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    bool swi = false;
    for(string str : strArr)
    {
        string temp = "";
        for(char c : str)
        {
            if(swi)
            {
                c = toupper(c);
            }
            else
            {
                c = tolower(c);
            }
            temp += c;
        }
        
        answer.push_back(temp);
        swi = !swi;
    }
    return answer;
}