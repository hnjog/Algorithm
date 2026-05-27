#include <string>
#include <vector>
#include <math.h>
using namespace std;

string solution(string my_string) {
    string answer = "";
    int value = (int)('a' - 'A');
    
    for(int i = 0; i < my_string.size();i++)
    {
        if(my_string[i] <= 'z' && my_string[i] >= 'a')
        {
            answer += (my_string[i] - value);
        }
        else
        {
            answer += (my_string[i] + value);
        }
    }
    return answer;
}