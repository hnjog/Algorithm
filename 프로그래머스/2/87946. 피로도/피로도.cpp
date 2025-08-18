#include <string>
#include <vector>

using namespace std;

void recur(const vector<vector<int>>& d, vector<bool>& bVec, int count, int result, int remainK, int& answer);

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    int dunSize = dungeons.size();
    vector<bool> bVector(dunSize, false);

    for (int i = 0; i < dunSize; i++)
    {
        if (k >= dungeons[i][0])
        {
            bVector[i] = true;
            recur(dungeons, bVector, 1, 1, k - dungeons[i][1], answer);
            bVector[i] = false;
        }
    }

    return answer;
}

void recur(const vector<vector<int>>& d, vector<bool>& bVec, int count, int result, int remainK, int& answer)
{
    int dSize = d.size();
    if (result > answer)
    {
        answer = result;
        
        if(count == dSize)
            return;
    }

    for (int i = 0; i < dSize; i++)
    {
        if (bVec[i])
            continue;

        if (remainK >= d[i][0])
        {
            bVec[i] = true;
            recur(d, bVec, count + 1, result + 1, remainK - d[i][1], answer);
            bVec[i] = false;
        }
    }
}