#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string,int> um;
    
    int ns = name.size();
    
    for(int i=0;i<ns;i++)
    {
        um[name[i]] = yearning[i];
    }
    
    for(auto& p : photo)
    {
        int r = 0;
        
        for(string& s : p)
        {
            r += um[s];
        }
        
        answer.push_back(r);
    }
    
    return answer;
}