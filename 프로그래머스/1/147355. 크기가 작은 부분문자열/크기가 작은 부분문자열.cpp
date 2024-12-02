#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int ts = t.size();
    int ps = p.size();
    
    for(int i = 0; i <= ts - ps;i++)
    {
        string temp(t.begin() + i, t.begin()+ i + ps);
        if((temp) <= (p))
        {
            answer++;
        }
    }
    return answer;
}