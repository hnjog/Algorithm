#include <string>
#include <map>

using namespace std;

bool solution(string s)
{
    map<char,int> m;
    
    for(char c : s)
    {
        m[c]++;
    }

    if(m['p'] + m['P'] == m['y'] + m['Y'])
        return true;

    return false;
}