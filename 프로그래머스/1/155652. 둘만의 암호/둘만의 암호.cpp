#include <string>
#include <unordered_set>

using namespace std;

string solution(string s, string skip, int index) {
    unordered_set<char> sset(skip.begin(),skip.end());
    
    for(char& c : s)
    {
        int nowCount = 0;
        while(nowCount < index)
        {
            c++;
            if(c > 'z')
                c = 'a';
            if(sset.find(c) != sset.end())
                continue;
            
            nowCount++;
        }
    }
    
    return s;
}