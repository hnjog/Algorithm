#include<algorithm>

using namespace std;

int getLV(int w, int h)
{
    int ret = 1;

    int iV = 2;
    int s = min(w, h);

    while (iV <= s)
    {
        if (w % iV == 0 &&
            h % iV == 0)
        {
            ret = iV;
        }

        iV++;
    }

    return ret;
}

long long solution(int w, int h) {
    long long answer = w * (long long)h;
    int lv = getLV(w, h);
    
    answer -= w;
    answer -= h;
    answer += lv;

    return answer;
}