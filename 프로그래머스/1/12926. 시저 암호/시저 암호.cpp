#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = s;
    
    for(int i = 1; i <= n;i++)
    {
        for(char& c : answer)
        {
            if(c == ' ')
                continue;
            
            if(c == 'z')
            {
                c = 'a';
            }
            else if(c == 'Z')
            {
                c = 'A';
            }
            else
            {
                c++;
            }
        }
    }
    
    return answer;
}