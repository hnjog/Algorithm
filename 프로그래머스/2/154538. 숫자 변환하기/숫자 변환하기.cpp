#include <vector>
#include<unordered_map>

using namespace std;

void recur(int now, int y, const int n, unordered_map<int, int>& m,int count)
{
    if (y == now)
    {
        if (m.find(y) == m.end())
        {
            m[y] = count;
        }
        else
        {
            if (m[y] > count)
            {
                m[y] = count;
            }
        }

        return;
    }

    if (now > y)
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

    recur(now + n, y, n, m, count + 1);
    recur(now * 2, y, n, m, count + 1);
    recur(now * 3, y, n, m, count + 1);

}

int solution(int x, int y, int n) {
    unordered_map<int, int> m;

    recur(x, y, n, m,0);

    int answer = -1;
    if (m.find(y) != m.end())
        answer = m[y];
    return answer;
}