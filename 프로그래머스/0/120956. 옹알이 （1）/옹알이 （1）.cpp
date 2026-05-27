#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    const string strs[4] = {"aya","ye","woo","ma"};
    int answer = 0;
    
    int size = babbling.size();
    
    for(int i = 0;i < size;i++)
    {
        string temp = babbling[i];
        int tSize = 0;
        for(int j = 0; j < 4; j++)
        {
            int found = temp.find(strs[j]);
            while(found != string::npos)
            {
                tSize += strs[j].size();
                
                found = temp.find(strs[j],found + 1);
            }
        }
        
        if(temp.size() == tSize)
        {
            answer++;
        }
    }
    
    
    return answer;
}