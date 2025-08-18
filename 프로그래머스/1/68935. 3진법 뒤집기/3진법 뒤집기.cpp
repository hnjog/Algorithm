#include <string>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string str = "";
    while(n >= 3)
    {
        str += to_string(n % 3);
        n /= 3;
    }
    str += to_string(n);
    
    for(int i = 0; i < str.size();i++)
    {
        answer *= 3;
        answer += (str[i] - '0');
    }
    
    return answer;
}