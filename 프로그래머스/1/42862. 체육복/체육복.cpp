#include <string>
#include <vector>
#include<algorithm>
#include<math.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 우선적으로 중복 제거하기 (unordered_set 쓰는게 제일 효율적일듯)
    for (auto it1 = lost.begin(); it1 != lost.end();)
    {
        bool bDelete = false;
        for (auto it2 = reserve.begin(); it2 != reserve.end();it2++)
        {
            if (*it1 == *it2)
            {
                bDelete = true;
                it1 = lost.erase(it1);
                reserve.erase(it2);
                break;
            }
        }

        if (!bDelete)
        {
            it1++;
        }
    }

    int s = lost.size();

    for (int i = 0; i < s; i++)
    {
        int l = lost[i];

        bool bFind = false;

        // 조건에 맞는 reserve가 있는가
        for (auto it = reserve.begin(); it != reserve.end(); it++)
        {
            if (abs(l - *it) == 1)
            {
                bFind = true;
                reserve.erase(it);
                break;
            }
        }

        if (bFind == false)
        {
            answer--;
        }
    }

    return answer;
}