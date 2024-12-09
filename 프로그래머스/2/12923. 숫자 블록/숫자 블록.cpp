#include <vector>

using namespace std;

typedef long long ll;

const ll MaxValue = 10000000;

ll getValue(ll value)
{
    if (value <= 1)
        return 0;

    ll ret = 1;

    for (ll i = 2; i * i <= value; i++)
    {
        if (value % i == 0)
        {
            ret = i;
            if (value / i <= MaxValue)
            {
                ret = value / i;
                break;
            }
        }
    }

    return ret;
}

vector<int> solution(ll begin, ll end) {
    vector<int> answer;
    for (ll i = begin; i <= end; i++)
    {
        answer.push_back(getValue(i));
    }
    return answer;
}