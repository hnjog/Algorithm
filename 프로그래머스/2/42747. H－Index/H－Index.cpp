#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> sC(citations.begin(),citations.end());
    
    sort(sC.begin(),sC.end(),greater<int>());
    
    int size = citations.size();
    
    for(int i = 0; i < size; i++)
    {
        if(sC[i] >= i + 1)
        {
            answer++;
        }
        else
        {
            break;
        }
    }
    
    return answer;
}