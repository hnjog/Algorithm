#include <string>
#include <vector>

using namespace std;

const int shotCount = 11;
const int points[shotCount] = { 10,9,8,7,6,5,4,3,2,1,0 };

void findRecur(int n,const vector<int>& info, vector<int>& temp, vector<int>& answer, vector<bool>& visit ,int targetSum, int nowSum, int nowCount,int& bestDis)
{
    // 기저 조건(종료)
    if (nowCount > n)
        return;

    if (nowCount == n &&
        nowSum > targetSum &&
        bestDis <= nowSum - targetSum)
    {
        bestDis = nowSum - targetSum;
        answer = temp;
        return;
    }

    for (int i = 0; i < shotCount; i++)
    {
        if (visit[i])
            continue;

        int tempCount = nowCount;
        int tempSum = nowSum;
        int tempTargetSum = targetSum;
        
        // 현재 시점에서 얻을 수 없는 과녁판임
        if (nowCount + info[i] + 1 > n)
        {
            continue;
        }
        
        tempSum += points[i];

        if(info[i] > 0)
            tempTargetSum -= points[i];

        temp[i] = info[i] + 1;
        tempCount += temp[i];
        visit[i] = true;

        findRecur(n, info, temp, answer, visit, tempTargetSum, tempSum, tempCount, bestDis);

        temp[i] = 0;
        visit[i] = false;
    }

    if (nowSum > targetSum &&
        bestDis <= nowSum - targetSum)
    {
        bestDis = nowSum - targetSum;
        temp[10] = n - nowCount;
        answer = temp;
    }
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(shotCount,0);
    vector<int> temp(shotCount,0);
    vector<bool> visit(shotCount,false);

    int targetSum = 0;
    for (int i = 0; i < shotCount; i++)
    {
        if (info[i] > 0)
            targetSum += points[i];
    }

    int bestDis = 0;
    findRecur(n, info, temp, answer, visit, targetSum, 0, 0, bestDis);

    if (bestDis == 0)
    {
        answer.clear();
        answer.push_back(-1);
    }

    return answer;
}
