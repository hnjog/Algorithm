#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int wSize = want.size();

    unordered_map<string, int> wantMap;
    for (int i = 0; i < wSize; i++)
    {
        wantMap[want[i]] = number[i];
    }

    int dSize = discount.size();

    for (int i = 0; i <= dSize - 10; i++)
    {
        unordered_map<string, int> tempMap;
        for (int j = i; j < i + 10; j++)
        {
            tempMap[discount[j]]++;
        }

        if (tempMap.size() != wantMap.size())
            continue;

        bool isSame = true;
        // 두 Map이 같은 요소를 지니는 지 확인하기
        for (int k = 0; k < wSize; k++)
        {
            if (tempMap[want[k]] != wantMap[want[k]])
            {
                isSame = false;
                break;
            }
        }

        if (isSame)
        {
            answer++;
        }
    }

    return answer;
}