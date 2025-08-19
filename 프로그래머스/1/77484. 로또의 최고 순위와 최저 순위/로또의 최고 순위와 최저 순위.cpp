#include <vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2,6);
    
    unordered_set<int> lSet;
    int zeroCount = 0;
    
    unordered_map<int,int> rank;
    rank[6] = 1;
    rank[5] = 2;
    rank[4] = 3;
    rank[3] = 4;
    rank[2] = 5;
    rank[1] = 6;
    rank[0] = 6;
    
    for(int l : lottos)
    {
        if(l == 0)
            zeroCount++;
        
        lSet.insert(l);
    }
    
    int baseCount = 0;
    
    for(int w : win_nums)
    {
        if(lSet.find(w) != lSet.end())
            baseCount++;
    }
    
    if(baseCount == 6)
    {
        answer[0] = 1;
        answer[1] = 1;
    }
    else
    {
        answer[1] = rank[baseCount];
    }
    
    if(zeroCount != 0)
    {
        answer[0] = rank[baseCount + zeroCount];
    }
    else
    {
        answer[0] = answer[1];
    }
    
    return answer;
}