#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.reserve(arr.size());
    
    for(int i : arr)
    {
        if(answer.empty() == false &&
          answer.back() == i)
        {
            continue;
        }
        
        answer.push_back(i);
    }

    return answer;
}