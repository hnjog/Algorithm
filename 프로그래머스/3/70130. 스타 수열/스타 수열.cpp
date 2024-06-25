#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;

    unordered_map<int, int> nc;
    for (int i = 0; i < a.size(); i++)
    {
        int value = a[i];

        if (i < a.size() - 1 && value == a[i + 1])
        {
            int count = 0;
            for (int j = i + 1; j < a.size(); j++)
            {
                if (value == a[j])
                {
                    count++;
                }
                else
                {
                    break;
                }
            }

            if (count > 2)
                i += count;
        }

        nc[value] = nc[value] + 1;
    }

    // nc에서 가장 개수 많은 수를 기준으로 벡터를 돌며 찾기

    int c = 0;
    int bestNums = 0;
    for (auto n : nc)
    {
        if (n.second > c)
        {
            c = n.second;
            bestNums = n.first;
        }
    }

    // bestNums를 기준으로 찾음
    for (int i = 0; i < a.size() - 1;i++) // i++ 등은 내부에서 해줄 예정이다
    {
        int value = a[i];
        int nextValue = a[i + 1];

        // 일단 두 수가 같다면 다음으로 넘긴다
        if (value == nextValue)
        {
            continue;
        }

        // 두 수는 같지 않으며,
        // 두 수 중 하나는 많은 수이다
        if (value == bestNums ||
            nextValue == bestNums)
        {
            answer++;
            i++;
        }
    }

    answer *= 2;

    return answer;
}