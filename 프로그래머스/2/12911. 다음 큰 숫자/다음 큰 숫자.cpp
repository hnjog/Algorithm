#include <vector>
#include<math.h>
#include<algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    while (n >= 1)
    {
        if (n % 2 != 0)
        {
            v.push_back(1);
            n--;
        }
        else
        {
            v.push_back(0);
        }
        n /= 2;
    }

    reverse(v.begin(), v.end());
    vector<int> v2(v);

    int idx = -1;
    const int vSize = v2.size();
    
    bool check = false;

    for (int i = 1; i < vSize; i++)
    {
        if (v2[i] == 0)
        {
            check = true;
        }
        else
        {
            if (check)
            {
                idx = i;
                check = false;
            }
        }
    }

    if (idx == -1)
    {
        v2.insert(v2.begin() + 1, 0);
        idx = 1;
    }
    else
    {
        // 만들기
        swap(v2[idx], v2[idx - 1]);
    }

    int oneCount = 0;
    for (int i = idx + 1; i < v2.size(); i++)
    {
        if (v2[i] == 1)
            oneCount++;
    }

    for (int i = v2.size() - 1; i >= idx + 1; i--)
    {
        if (oneCount > 0)
        {
            v2[i] = 1;
            oneCount--;
        }
        else
        {
            v2[i] = 0;
        }
    }

    int value = 0;

    for (int i = v2.size() - 1; i >= 0; i--)
    {
        answer += v2[i] * pow(2,value);
        value++;
    }

    return answer;
}