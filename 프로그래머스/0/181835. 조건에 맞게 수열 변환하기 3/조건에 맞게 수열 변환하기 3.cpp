#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    for(int n : arr)
    {
        if(k % 2 == 0)
        {
            answer.push_back(n + k);
        }
        else
        {
            answer.push_back(n * k);
        }
    }
    
    return answer;
}