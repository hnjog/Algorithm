#include <vector>
#include<unordered_map>
#include<math.h>
#include<limits.h>

using namespace std;

bool check(int nowC,int nowSB, int tC,int tSB)
{
    if (nowC + 1 < tC ||
        (nowC + 1 == tC &&
            nowSB > tSB))
        return true;

    return false;
}

vector<int> solution(int target) {
    vector<int> answer;

    struct dartInfo
    {
        int dartCount = 0;
        int singleOrBoolCount = 0;
    };

    unordered_map<int, dartInfo> dp;
    dp.reserve(100001);

    dp[50] = dartInfo{ 1,1 };
    for (int i = 1; i <= 20; i++)
    {
        // 기본값들은 세팅해줌
        dp[i] = dartInfo{ 1,1 };

        // 초기 세팅이 제일 강력하므로 이미 존재한다면 추가 x
        if (dp.find(i * 2) == dp.end())
        {
            dp[i * 2] = dartInfo{ 1,0 };
        }

        if (dp.find(i * 3) == dp.end())
        {
            dp[i * 3] = dartInfo{ 1,0 };
        }
    }

    // bottom-up
    for (int i = 1; i <= target; i++)
    {
        int nowCount = dp[i].dartCount;
        int nowSBCount = dp[i].singleOrBoolCount;

        int dI = i + (i % 20)* 2;
        int tI = i + (i % 20)* 3;
        int boolsI = i + 50;

        if (dp.find(dI) == dp.end() ||
            check(nowCount, nowSBCount, dp[dI].dartCount, dp[dI].singleOrBoolCount))
        {
            dp[dI] = dartInfo{ nowCount + 1, nowSBCount };
        }

        if (dp.find(tI) == dp.end() ||
            check(nowCount, nowSBCount, dp[tI].dartCount, dp[tI].singleOrBoolCount))
        {
            dp[tI] = dartInfo{ nowCount + 1, nowSBCount };
        }

        if (dp.find(boolsI) == dp.end() ||
            check(nowCount, nowSBCount + 1, dp[boolsI].dartCount, dp[boolsI].singleOrBoolCount))
        {
            // bools Eye는 개수에 추가시켜줘야 함
            dp[boolsI] = dartInfo{ nowCount + 1, nowSBCount + 1 };
        }

        // for문 돌려서 더해주기
        for (int j = 1; j <= 20; j++)
        {
            int t = i + j;
            int dt = i + j * 2;
            int tt = i + j * 3;

            if (dp.find(i + j) == dp.end() ||
                check(nowCount, nowSBCount + 1, dp[i + j].dartCount, dp[i + j].singleOrBoolCount))
            {
                dp[i + j] = dartInfo{ nowCount + 1, nowSBCount + 1 };
            }

            if (dp.find(dt) == dp.end() || 
                check(nowCount, nowSBCount, dp[dt].dartCount, dp[dt].singleOrBoolCount))
            {
                dp[dt] = dartInfo{ nowCount + 1, nowSBCount };
            }

            if (dp.find(tt) == dp.end() ||
                check(nowCount, nowSBCount, dp[tt].dartCount, dp[tt].singleOrBoolCount))
            {
                dp[tt] = dartInfo{ nowCount + 1, nowSBCount };
            }
        }
    }

    answer.push_back(dp[target].dartCount);
    answer.push_back(dp[target].singleOrBoolCount);

    return answer;
}
