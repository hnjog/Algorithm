#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    int count = 0;
    for(char c : myString)
    {
        if(c == 'x')
        {
            answer.push_back(count);
            count = 0;
        }
        else
        {
            count++;
        }
    }
    
    answer.push_back(count);
    
    return answer;
}