#include <vector>
#include <stdint.h>

using namespace std;

typedef long long ll;

bool isSuccess(ll timeX, int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
    int tSize = t.size();
    ll fullAmountG = 0;// 총 옮길 수 있는 금의 양 : 이 양이 a보다 작으면 실패
    ll fullAmountS = 0;// 총 옮길 수 있는 은의 양 : 이 양이 b보다 작으면 실패
    ll fullAmountM = 0;// 총 옮길 수 있는 광물의 양 : 총 옮길 수 있는 광물의 양이 a + b 보다 작다면 결국 실패

    for (int i = 0; i < tSize; i++)
    {
        ll timeCount = (timeX - t[i]) / (t[i] * 2) + 1; // 맨 처음은 편도로 옮길 수 있음, 그 이후로는 왕복
        ll fullAmount = w[i] * timeCount;

        if (fullAmount < g[i])
        {
            fullAmountG += fullAmount;
        }
        else
        {
            fullAmountG += g[i];
        }

        if (fullAmount < s[i])
        {
            fullAmountS += fullAmount;
        }
        else
        {
            fullAmountS += s[i];
        }

        // 옮기려는 총량이 현재 가능한 양보다 작은 경우
        if (fullAmount < s[i] + g[i])
        {
            fullAmountM += fullAmount;
        }
        else
        {
            fullAmountM += (s[i] + g[i]);
        }
    }

    if (fullAmountG < a)
        return false;
    
    if (fullAmountS < b)
        return false;

    if (fullAmountM < a + b)
        return false;

    return true;
}

ll solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    ll answer = -1;
    ll low = 0, high = 10e14 * 3;

    while (low < high)
    {
        ll mid = (low + high) / 2;

        if (isSuccess(mid, a, b, g, s, w, t))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    answer = low;
    return answer;
}