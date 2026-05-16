#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer = arr;
    for(auto& v : queries)
    {
        swap(answer[v[0]],answer[v[1]]);
    }
    return answer;
}