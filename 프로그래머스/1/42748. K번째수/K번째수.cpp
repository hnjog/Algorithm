#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    
    
    for(const auto& v : commands)
    {
        int start = v[0] - 1;
        int end = v[1] - 1;
        int target = v[2] - 1;
        
        for(int i = start; i <= end; i++)
        {
            temp.push_back(array[i]);
        }
        
        sort(temp.begin(),temp.end());
        
        answer.push_back(temp[target]);
        temp.clear();
    }
    
    return answer;
}