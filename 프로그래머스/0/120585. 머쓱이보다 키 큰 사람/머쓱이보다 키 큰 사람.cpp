#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    sort(array.begin(),array.end(),greater<int>());
    for(int i = 0; i < array.size();i++)
    {
        if(array[i] > height)
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