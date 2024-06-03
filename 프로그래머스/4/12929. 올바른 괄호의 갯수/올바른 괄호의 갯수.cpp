#include <string>
#include <vector>

using namespace std;

void dfs(int& answer, string& temp, int fc, int rc)
{
    // 종료 조건 (fc 와 rc가 모두 0)
    if (fc == 0 && rc == 0)
    {
        answer++;
        return;
    }
    
    // 백트래킹
    // 전방 괄호 추가
    if(fc > 0)
    {
        temp.push_back('(');
        dfs(answer, temp, fc - 1, rc);
        temp.pop_back();
    }

    // 후방 괄호 추가
    if(rc > 0 && rc > fc)
    {
        temp.push_back(')');
        dfs(answer, temp, fc, rc - 1);
        temp.pop_back();
    }
}

int solution(int n) {
    string temp = "";
    int answer = 0;
    
    dfs(answer, temp, n, n);

    

    return answer;
}