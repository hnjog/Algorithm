#include <string>
#include <vector>
#include<algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long low = 1;
    long long high = (long long)times.back() * n;
    long long answer = high;

    while (low <= high) 
    {
        long long mid = (low + high) / 2;
        long long count = 0;

        // mid 시간 동안 모든 심사관이 처리할 수 있는 인원의 총합 계산
        for (int time : times) 
        {
            count += mid / time;
        }

        // 처리 가능한 인원 수가 n보다 작으면, 더 많은 시간이 필요함
        if (count < n) 
        {
            low = mid + 1;
        }
        // 처리 가능한 인원 수가 n보다 크거나 같으면, 더 적은 시간도 가능할 수 있음
        else 
        { 
            answer = min(answer, mid);
            high = mid - 1;
        }
    }

    return answer;
}