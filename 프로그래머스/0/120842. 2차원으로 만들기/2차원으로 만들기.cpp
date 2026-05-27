#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    int size = num_list.size() / n;
    int index = 0;
    
    while(index < size)
    {
        answer.push_back(vector<int>());
        
        for(int i = 0; i < n; i++)
        {
            answer[index].push_back(num_list[index * n + i]);
        }
        
        index++;
    }
    
    return answer;
}