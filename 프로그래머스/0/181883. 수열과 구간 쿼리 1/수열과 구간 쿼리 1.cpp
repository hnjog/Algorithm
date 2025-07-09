#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    
    for(const auto& vec : queries)
    {
        int s = vec[0];
        int t = vec[1];
        for(int i = s;i <=t;i++)
        {
            arr[i]++;
        }
    }
    
    return arr;
}