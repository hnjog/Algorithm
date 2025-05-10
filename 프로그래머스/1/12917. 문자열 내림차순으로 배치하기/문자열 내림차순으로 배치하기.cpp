#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = s;
    sort(answer.begin(),answer.end(),[](char a, char b)
         {
             if(a >= 'A' && a <= 'Z')
                 a -= 'A';
             if(b >= 'A' && b <= 'Z')
                 b -= 'A';
                 
             return a > b;
    });
    return answer;
}