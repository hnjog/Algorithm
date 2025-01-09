#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    for(int i = 0; i < n;i++)
    {
        answer.push_back(vector<int>());
        for(int j = 0; j < n;j++)
        {
            if(i == j)
                answer[i].push_back(1);
            else
                answer[i].push_back(0);
        }
    }
    return answer;
}