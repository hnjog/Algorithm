#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getv(string& val)
{
    if(val == "code")
        return 0;
    
    if(val == "date")
        return 1;
    
    if(val == "maximum")
        return 2;
    
    if(val == "remain")
        return 3;
    
    return -1;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int ev = getv(ext);
    int sv = getv(sort_by);
    
    sort(data.begin(),data.end(),
         [=](const auto& a,const auto& b)
         {
             return a[ev] < b[ev];
         });
    
    for(auto& d : data)
    {
        if(d[ev] >= val_ext)
            continue;
        
        answer.push_back(d);
    }
    
    sort(answer.begin(),answer.end(),
         [=](const auto& a,const auto& b)
         {
             return a[sv] < b[sv];
         });
    
    return answer;
}