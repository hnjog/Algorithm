#include <string>
#include<math.h>

using namespace std;

void check(const string& dartResult, int nowIndex,int& answer,int& now, int& prev)
{
    if (nowIndex + 1 >= dartResult.size())
        return;

    if (dartResult[nowIndex + 1] == '*')
    {
        answer -= now;
        now *= 2;
        answer += now;
        answer += prev;
    }
    else if(dartResult[nowIndex + 1] == '#')
    {
        answer -= now;
        now *= -1;
        answer += now;
    }
}

int solution(string dartResult) {
    int answer = 0;

    int now = 0;
    int prev = 0;

    for (int i = 0; i < dartResult.size(); i++)
    {
        char c = dartResult[i];

        if (c >= '0' && c <= '9')
        {
            prev = now;

            if (i > 0 && dartResult[i-1] == '1' && c == '0')
            {
                now = 10;
            }
            else
            {
                now = int(c - '0');
            }

            continue;
        }

        if (c == 'S')
        {
            answer += now;
            check(dartResult, i, answer,now,prev);
        }

        if (c == 'D')
        {
            now = pow(now, 2);
            answer += now;
            check(dartResult, i, answer, now, prev);
        }

        if (c == 'T')
        {
            now = pow(now, 3);
            answer += now;
            check(dartResult, i, answer, now, prev);
        }
    }

    return answer;
}
