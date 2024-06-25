#include <vector>
#include<limits.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int minV = INT_MAX;
    int maxV = -1;

    for (int s : stones)
    {
        if (s < minV)
            minV = s;

        if (s > maxV)
            maxV = s;
    }

    int left = minV;
    int right = maxV;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        bool isSuccess = true;

        // 중간값을 빼가며 연속해서 k를 통과가능한지 확인하는 로직
        int zeroCount = k;
        for (int stoneCount : stones)
        {
            if (stoneCount - mid <= 0)
            {
                zeroCount--;
            }
            else
            {
                zeroCount = k;
            }

            if (zeroCount <= 0)
            {
                isSuccess = false;
                break;
            }
        }

        if (isSuccess == true)
        {
            // 더 큰 수 검사
            left = mid + 1;
        }
        else
        {
            // 실패시 더 작은 수로 하여 재 검색
            right = mid - 1;
        }
    }

    // 통과가능한 가장 큰 수
    answer = left;

    return answer;
}