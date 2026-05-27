#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    int size = numbers.size();
    
    if(direction == "right")
    {
        answer.push_back(numbers[size - 1]);
        for(int i = 0; i < size - 1;i++)
        {
            answer.push_back(numbers[i]);
        }
    }
    else
    {
        for(int i = 1; i < size;i++)
        {
            answer.push_back(numbers[i]);
        }
        answer.push_back(numbers[0]);
    }
    return answer;
}