#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    int nSize = numlist.size();
    for(int i = 0; i <nSize;i++)
    {
        if(numlist[i] % n == 0)
        {
            answer.push_back(numlist[i]);
        }
    }
    
    return answer;
}