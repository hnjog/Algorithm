#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
    
    int eSize = ex.size();
    
    for(string str : str_list)
    {
        int sSize = str.size();
        
        bool isIn = false;
        int idx = 0;
        
        for(int i = 0; i <= sSize;i++)
        {
            if(idx >= eSize)
            {
                isIn = true;
                break;
            }
            
            if(i == sSize)
                break;
            
            if(str[i] == ex[idx])
            {
                idx++;
            }
        }
        
        if(isIn == false)
            answer += str;
        
    }
    
    return answer;
}