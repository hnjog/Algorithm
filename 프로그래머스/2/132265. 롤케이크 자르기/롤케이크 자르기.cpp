#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int,int> rightMap;
    for(int i = 0; i <topping.size();i++)
    {
        rightMap[topping[i]]++;
    }
    
    unordered_map<int,int> leftMap;
    for(int i = 0; i < topping.size();i++)
    {
        leftMap[topping[i]]++;
        rightMap[topping[i]]--;
        if(rightMap[topping[i]] == 0)
            rightMap.erase(topping[i]);
        
        if(leftMap.size() == rightMap.size())
            answer++;
    }
    
    return answer;
}