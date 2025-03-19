#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;

const ll alphaBase = 26;


char alpha[alphaBase] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

string getStr(ll n)
{
    string ret = "";
    while (n >= alphaBase)
    {
        int v = n % alphaBase;
        if (v == 0)
        {
            v = alphaBase;
            n--;
        }
        ret += alpha[v - 1];
        n /= alphaBase;
    }

    if (n <= 0)
        n = alphaBase;
    ret += alpha[n - 1];

    return ret;
}

ll getValue(string str)
{
    ll ret = 0;
    reverse(str.begin(), str.end());

    int idx = 0;
    for (char c : str)
    {
        int v = int(c - 'a') + 1;
        ret += v * pow(alphaBase, idx);
        idx++;
    }

    return ret;
}

string solution(ll n, vector<string> bans) {
    string answer = "";

    vector<ll> bansNum;
    for (string str : bans)
    {
        bansNum.push_back(getValue(str));
    }

    sort(bansNum.begin(), bansNum.end());

    for (ll bn : bansNum)
    {
        if (bn <= n)
            n++;
        else
            break;
    }

    answer = getStr(n);
    reverse(answer.begin(), answer.end());

    return answer;
}