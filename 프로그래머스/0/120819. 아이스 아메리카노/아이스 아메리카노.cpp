#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    
    int ameValue = 5500;
    
    int count = 0;
    int lastValue = 0;
    
    while(money >= ameValue)
    {
        money -= ameValue;
        count++;
    }
    
    lastValue = money;
    
    answer.push_back(count);
    answer.push_back(lastValue);
    
    return answer;
}