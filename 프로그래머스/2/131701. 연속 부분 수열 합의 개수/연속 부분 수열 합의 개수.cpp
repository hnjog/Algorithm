#include <vector>
#include<unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int eSize = elements.size();
    unordered_set<int> vs;
    
    for (int i = 1; i <= eSize; i++) // 길이
    {
        for (int j = 0; j < eSize; j++) // 시작 지점
        {
            int sum = 0;
            // 실제 계산 용
            for (int k = j; k < j + i; k++)
            {
                int idx = k;
                if (idx >= eSize)
                    idx -= eSize;

                sum += elements[idx];
            }

            vs.insert(sum);
        }
    }

    return vs.size();
}