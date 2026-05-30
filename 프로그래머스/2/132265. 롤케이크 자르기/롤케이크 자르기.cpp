#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    unordered_map<int,int> um1,um2;
    for(int t : topping)
    {
        um2[t]++;
    }
    
    for(int i=0;i<topping.size();i++)
    {
        um1[topping[i]]++;
        um2[topping[i]]--;
        if(um2[topping[i]] == 0)
            um2.erase(topping[i]);
        
        if(um1.size() == um2.size())
            answer++;
    }
    
    return answer;
}