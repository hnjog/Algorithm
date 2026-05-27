#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    vector<pair<int,int>> pv;
    
    for(int i = 0; i < array.size();i++)
    {
        pv.push_back(make_pair(array[i],i));
    }
    
    sort(pv.begin(),pv.end(),[](pair<int,int> a, pair<int,int> b)->bool{return a.first > b.first;});
    
    answer.push_back(pv[0].first);
    answer.push_back(pv[0].second);
    
    return answer;
}