#include <string>
#include <vector>

using namespace std;

bool solution(string s) 
{
    if((s.size() == 4 || s.size() == 6) == false)
        return false;
    
    for(char c : s)
    {
        if(c >= '0' && c <= '9')
            continue;
        
        return false;
    }
    
    return true;
}