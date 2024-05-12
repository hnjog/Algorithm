#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int cSize = clothes.size();
    unordered_map<string,int> m; // 타입, 개수
    
    for(int i = 0; i < cSize;i++)
    {
        if(m.find(clothes[i][1]) == m.end())
        {
            m[clothes[i][1]] = 1;
        }
        else
        {
            m[clothes[i][1]] += 1;
        }
    }
    
    for(auto a : m)
    {
        answer *= (a.second + 1);
    }
    
    answer--;
    
    return answer;
}