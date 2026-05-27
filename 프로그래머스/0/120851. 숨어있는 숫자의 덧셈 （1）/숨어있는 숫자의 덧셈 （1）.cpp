#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    int size = my_string.size();
    
    for(int i = 0; i < size;i++)
    {
        if(my_string[i] >= '0' && my_string[i] <= '9')
        {
            answer += (int)(my_string[i] - '0');
        }
        
    }
    
    return answer;
}