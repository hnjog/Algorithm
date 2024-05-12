#include <string>
#include <vector>

using namespace std;

void recur(const vector<vector<int>>& d, vector<bool>& bVec, int count, int& result, int& remainK, int& answer);

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int dunSize = dungeons.size();
    int tempK = k; // 이걸 변형시켜 쓸 예정
    vector<bool> bVector(dunSize, false);

    for (int i = 0; i < dunSize; i++)
    {
        if (tempK >= dungeons[i][0])
        {
            bVector[i] = true;
            tempK -= dungeons[i][1];
            int res = 1;
            recur(dungeons, bVector, 1, res, tempK, answer);
            bVector[i] = false;
            tempK = k;
        }
    }

    return answer;
}

void recur(const vector<vector<int>>& d, vector<bool>& bVec, int count, int& result, int& remainK, int& answer)
{
    int dSize = d.size();
    if (result > answer)
    {
        answer = result;

        if (count == dSize)
            return;
    }

    for (int i = 0; i < dSize; i++)
    {
        if (bVec[i])
            continue;

        if (remainK >= d[i][0])
        {
            bVec[i] = true;
            int originK = remainK;
            remainK -= d[i][1];
            count++;
            result++;
            recur(d, bVec, count, result, remainK, answer);
            count--;
            result--;
            remainK = originK;
            bVec[i] = false;
        }
    }
}