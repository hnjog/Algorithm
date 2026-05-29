#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int>& com : commands)
    {
        int start = com[0] - 1;
        int end = com[1] - 1;
        int target = com[2] - 1;
        vector<int> temp;
        for (int i = start; i <= end; i++)
        {
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[target]);
    }
    return answer;
}