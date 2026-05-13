#include <string>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    int ms = myString.size();
    int ps = pat.size();
    
    for(int i=0; i <= ms -ps;i++)
    {
        string str = myString.substr(i,ps);
        if(str == pat)
            answer++;
    }
    
    return answer;
}