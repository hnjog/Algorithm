#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool bRightV(vector<vector<string>>& park,int v,int sy, int sx)
{
    int h = park.size();
    int w = park[0].size();

    if (sy + v >= h ||
        sx + v >= w)
        return false;

    for (int i = sy; i <= sy + v; i++)
    {
        for (int j = sx; j <= sx + v; j++)
        {
            if (park[i][j] != "-1")
                return false;
        }
    }

    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;

    sort(mats.begin(), mats.end(),greater<int>());

    int h = park.size();
    int w = park[0].size();

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (park[i][j] != "-1")
                continue;

            for (int m : mats)
            {
                if (bRightV(park, m - 1, i, j) == true)
                {
                    if (m == mats[0])
                        return m;

                    if(answer < m)
                        answer = m;
                    break;
                }
            }
        }
    }

    return answer;
}