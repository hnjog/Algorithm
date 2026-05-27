#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    int size = my_string.size();
    
    for(int i = 0; i < size;i++)
    {
        if(my_string[i] >= '0' && my_string[i] <= '9')
        {
            answer.push_back((int)(my_string[i] - '0'));
        }
        
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}