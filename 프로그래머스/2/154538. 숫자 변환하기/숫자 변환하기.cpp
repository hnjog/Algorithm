#include <vector>
#include<unordered_map>

using namespace std;

void recur(int now, int x, int n, unordered_map<int, int>& m,int count)
{
    if (x == now)
    {
        if (m.find(x) == m.end())
        {
            m[x] = count;
        }
        else
        {
            if (m[x] > count)
            {
                m[x] = count;
            }
        }

        return;
    }

    if (now < x)
        return;

    if (m.find(now) == m.end())
    {
        m[now] = count;
    }
    else
    {
        if (m[now] > count)
        {
            m[now] = count;
        }
        else
        {
            return;
        }
    }

    if(now % 3 == 0)
        recur(now / 3, x, n, m, count + 1);
    if(now % 2 == 0)
        recur(now / 2, x, n, m, count + 1);
    recur(now - n, x, n, m, count + 1);
}

int solution(int x, int y, int n) {
    unordered_map<int, int> m;

    recur(y, x, n, m,0);

    int answer = -1;
    if (m.find(x) != m.end())
        answer = m[x];
    return answer;
}