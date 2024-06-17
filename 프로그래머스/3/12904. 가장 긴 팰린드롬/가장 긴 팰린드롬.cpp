#include <string>
#include<vector>

using namespace std;

int solution(string s){
    int answer = 1;
    const int sSize = s.size();

    vector<vector<bool>> dp(sSize, vector<bool>(sSize, false));

    for (int i = 0; i < sSize; i++)
    {
        dp[i][i] = true;
    }

    for (int i = 0; i < sSize - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            answer = 2;
            dp[i][i + 1] = true;
        }
    }

    // 크기가 3이상인 경우
    for (int length = 3; length <= sSize; length++)
    {
        for (int i = 0; i <= sSize - length; i++)
        {
            if (s[i] == s[i + length - 1])
            {
                if (dp[i + 1][i + length - 2])
                {
                    answer = length;
                    dp[i][i + length - 1] = true;
                }
            }
        }
    }

    return answer;
}
