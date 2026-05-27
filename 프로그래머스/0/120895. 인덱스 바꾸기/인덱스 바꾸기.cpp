#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = my_string;
    
    char c1,c2;
    c1 = my_string[num1];
    c2 = my_string[num2];
    
    answer[num1] = c2;
    answer[num2] = c1;
    
    return answer;
}