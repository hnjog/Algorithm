#include <vector>
#include<unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int eSize = elements.size();
    unordered_set<int> vs;
    
    for (int i = 0; i < eSize; i++) // 길이
    {
        int sum = 0;
        for (int j = i; j < i + eSize; j++) // 시작 지점
        {
            // 실제 계산 용
            // 반복문을 추가로 돌지 않더라도
            // 해당 시작 지점에서 크기만큼 더해주는 방식으로 더 빠르게 풀 수 있음
            int idx = j % eSize;

            sum += elements[idx];
            vs.insert(sum);
        }
    }

    return vs.size();
}