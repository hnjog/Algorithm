#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char,int> umap;
    
    for(int i = 0; i < s.size();i++)
    {
        char c = s[i];
        
        if(umap.find(c) == umap.end())
        {
            umap[c] = i;
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - umap[c]);
            umap[c] = i;
        }
    }
    
    return answer;
}