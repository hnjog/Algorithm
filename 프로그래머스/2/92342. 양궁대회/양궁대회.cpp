#include <vector>

using namespace std;

const int values[11] = { 10,9,8,7,6,5,4,3,2,1,0 };
int bestDis = 0;
vector<int> bestAnswer;

void recur(int n, const vector<int>& info, vector<int>& nows, int count, int idx)
{
    if (count > n || idx >= 11)
        return;
    // 종료 조건
    if (count == n)
    {
        // 점수 계산
        int myPoint = 0;
        int AnotherPoint = 0;

        for (int i = 0; i < 10; i++)
        {
            if (nows[i] > info[i])
                myPoint += values[i];
            else if (info[i] != 0)
                AnotherPoint += values[i];
        }

        int dis = myPoint - AnotherPoint;

        if (dis > bestDis)
        {
            bestDis = dis;
            bestAnswer = nows;
        }
        else if (dis == bestDis&&
            dis != 0)
        {
            bool bChanged = false;
            for (int i = 10; i >= 0; i--)
            {
                if (nows[i] > bestAnswer[i])
                {
                    bChanged = true;
                    break;
                }
                else if (bestAnswer[i] > nows[i])
                    break;
            }

            if (bChanged)
                bestAnswer = nows;
        }

        return;
    }

    for (int i = idx; i < 11; i++)
    {
        int infV = (info[i] + 1);
        int remains = n - count;

        if (infV > remains)
            infV = remains;

        nows[i] += infV;
        recur(n, info, nows, count + infV, idx + 1);
        nows[i] -= infV;
    }

}

vector<int> solution(int n, vector<int> info) {
    vector<int> temp(11);

    recur(n, info, temp, 0, 0);

    if (bestDis == 0)
        return { -1 };

    return bestAnswer;
}