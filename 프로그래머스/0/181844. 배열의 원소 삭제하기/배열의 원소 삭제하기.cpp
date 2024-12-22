#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    set<int> s(delete_list.begin(),delete_list.end());
    for(int a : arr)
    {
        if(s.find(a) == s.end())
            answer.push_back(a);
    }
    return answer;
}