#include <string>
#include <vector>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    for(auto d : dic)
    {
        bool isOkay = true;
        for(auto s : spell)
        {
            size_t found = d.find(s);
            if(found == string::npos)
            {
                isOkay = false;
                break;
            }
        }
        
        if(isOkay)
        {
            answer = 1;
            break;
        }
    }
    return answer;
}