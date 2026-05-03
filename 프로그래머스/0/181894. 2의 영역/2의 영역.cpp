#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int si = -1,ei = -1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i] == 2)
        {
            si = i;
            break;
        }
    }
    
    for(int i =arr.size() - 1; i >=0;i--)
    {
        if(arr[i] == 2)
        {
            ei = i;
            break;
        }
    }
    
    if(si == -1)
    {
        answer.push_back(-1);
    }
    else
    {
        for(int i=si; i <=ei;i++)
        {
            answer.push_back(arr[i]);
        }
    }
    return answer;
}