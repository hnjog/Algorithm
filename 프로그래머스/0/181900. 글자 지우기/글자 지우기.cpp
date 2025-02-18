#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    set<int> s(indices.begin(),indices.end());
    
    for(int i=0;i<my_string.size();i++)
    {
        if(s.find(i) == s.end())
        {
            answer += my_string[i];
        }
    }
    
    return answer;
}