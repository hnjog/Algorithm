#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {

    string t1 = "", t2 = "";
    for(char c : myString)
    {
        t1 += tolower(c);
    }
    
    for(char c : pat)
    {
        t2 += tolower(c);
    }
    
    if(t1.find(t2) == string::npos)
        return 0;
    
    return 1;
}