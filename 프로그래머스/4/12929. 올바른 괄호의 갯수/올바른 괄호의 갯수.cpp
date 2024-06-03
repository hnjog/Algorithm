#include <string>
#include <vector>
#include<set>

using namespace std;

void dfs(set<string>& ss, string& temp, int fc, int rc)
{
    // 종료 조건 (fc 와 rc가 모두 0)
    if (fc == 0 && rc == 0)
    {
        ss.insert(temp);
        return;
    }
    
    // 백트래킹
    // 전방 괄호 추가
    if(fc > 0)
    {
        temp.push_back('(');
        dfs(ss, temp, fc - 1, rc);
        temp.pop_back();
    }

    // 후방 괄호 추가
    if(rc > 0 && rc > fc)
    {
        temp.push_back(')');
        dfs(ss, temp, fc, rc - 1);
        temp.pop_back();
    }
}

int solution(int n) {
    set<string> ss;

    string temp = "";

    dfs(ss, temp, n, n);

    int answer = ss.size();

    return answer;
}