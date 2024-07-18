#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    vector<vector<int>> dp(land.size() + 1, vector<int>(4, 0));

    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (j == k)
                    continue;

                if (dp[i + 1][k] >= dp[i][j] + land[i][j])
                    continue;

                dp[i + 1][k] = dp[i][j] + land[i][j];
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (dp[land.size()][i] > answer)
            answer = dp[land.size()][i];
    }

    return answer;
}