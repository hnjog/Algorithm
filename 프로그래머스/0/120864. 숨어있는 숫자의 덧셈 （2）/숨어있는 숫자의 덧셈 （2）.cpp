#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    int sSize = my_string.size();
    
    for(int i = 0; i <sSize;i++)
    {
        if(isdigit(my_string[i]))
        {
            int value = (int)(my_string[i] - '0');
            int ind = i + 1;
            while(ind < sSize)
            {
                if(isdigit(my_string[ind]))
                {
                    value *= 10;
                    value += (int)(my_string[ind] - '0');
                    ind++;
                    i++;
                }
                else
                {
                    break;
                }
            }
            answer += value;
        }
    }
    
    return answer;
}