#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance); // 도착점 넣어두기


    int answer = 0;
    int left = 1; // 가능한 바위 사이 거리의 최솟값
    int right = distance; // 처음과 끝의 거리값

    while (left <= right)
    {
        // 중간 값
        int mid = (left + right) / 2;
        int removeCount = 0;
        int lastRockPos = 0; // 시작점(0)에서 시작

        for (int rock : rocks)
        {
            // rock의 위치가 가장 마지막 위치
            if (rock - lastRockPos < mid)
            {
                // mid보다 '최소 거리'가 먼 경우는 제거해야 한다
                removeCount++;
            }
            else
            {
                // 그렇지 않다면 바위 위치 갱신
                lastRockPos = rock;
            }
        }

        // left 와 right의 범위 처리

        // 너무 많은 바위를 제거한 경우
        // 현재 '추정'한 최소값이 너무 크다는 의미
        if (removeCount > n)
        {
            right = mid - 1;
        }
        else // removeCount가 n이하인 경우는 더 큰값이 있는지를 탐색
        {
            left = mid + 1;
            answer = mid;
        }

    }
    
    return answer;
}