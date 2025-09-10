#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    unordered_map<long, long> weightsMap;

    for (int w : weights)
    {
        weightsMap[w]++;
    }

    for (auto it1 = weightsMap.begin(); it1 != weightsMap.end(); it1++)
    {
        answer += (it1->second * (it1->second - 1)) / 2;
    }

    for (auto it1 = weightsMap.begin(); it1 != weightsMap.end(); it1++)
    {
        for (auto it2 = next(it1); it2 != weightsMap.end(); it2++)
        {
            long w1 = it1->first;
            long w2 = it2->first;

            bool isFair = false;
            if (w1 == w2)
                isFair = true;
            else
            {
                long w12 = w1 * 2;
                long w13 = w1 * 3;
                long w14 = w1 * 4;

                long w22 = w2 * 2;
                long w23 = w2 * 3;
                long w24 = w2 * 4;

                if (w12 == w23 ||
                    w12 == w24 ||
                    w13 == w22 ||
                    w13 == w24 ||
                    w14 == w22 ||
                    w14 == w23)
                    isFair = true;
            }

            if (isFair)
            {
                answer += (long long)it1->second * it2->second;
            }
        }
    }

    return answer;
}