#include <string>
#include<math.h>

using namespace std;

bool check(const string& dartResult, int nowIndex,int& answer,int& now, int& prev)
{
    if (nowIndex + 1 >= dartResult.size())
        return false;
    
    if(dartResult[nowIndex + 1] != '*' &&
      dartResult[nowIndex + 1] != '#')
        return false;
    
    answer -= now;
    
    if (dartResult[nowIndex + 1] == '*')
    {
        now *= 2;
        answer += now;
        answer += prev;
        return true;
    }
    
    now *= -1;
    answer += now;
    
    return true;
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

        if (c == 'S' ||
            c == 'D' ||
            c == 'T')
        {
            if (c == 'D')
                now = pow(now, 2);
            else if (c == 'T')
                now = pow(now, 3);

            answer += now;
            if (check(dartResult, i, answer, now, prev))
                i++;
        }
    }

    return answer;
}