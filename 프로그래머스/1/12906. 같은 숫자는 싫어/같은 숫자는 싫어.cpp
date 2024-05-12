#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int arrSize = arr.size();
    answer.reserve(arrSize);
    
    for(int i = 0; i < arrSize;i++)
    {
        if(answer.size() != 0 && answer.back() == arr[i])
        {
            continue;
        }
        answer.push_back(arr[i]);
    }
    

    return answer;
}