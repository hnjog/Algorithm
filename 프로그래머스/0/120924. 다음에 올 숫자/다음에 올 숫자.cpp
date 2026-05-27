#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int amount1 = common[1] - common[0];
    int amount2 = common[2] - common[1];
    
    bool isDis = amount1 == amount2;
    
    int size = common.size();
    if(isDis == true)
    {
        answer = common[size - 1] + amount1;
    }
    else
    {
        answer = common[size - 1] * (amount2 / amount1);
    }
    
    return answer;
}