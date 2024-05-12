#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& money, int start, int end) 
{
    int n = end - start + 1;

    if (n <= 0) 
        return 0;

    vector<int> dp(n, 0);
    dp[0] = money[start];

    for (int i = 1; i < n; i++) 
    {
        int iValue = 0;
        if (i > 1)
        {
            iValue = dp[i - 2];
        }

        dp[i] = max(dp[i - 1], iValue + money[start + i]);
    }

    return dp[n - 1];
}

int solution(vector<int> money) 
{
    int size = money.size();

    // 첫 번째 를 선택한 경우 (마지막은 선택 범위에 x)
    int case1 = rob(money, 0, size - 2);

    // 첫 번째를 선택하지 않은 경우(마지막을 선택 범위에)
    int case2 = rob(money, 1, size - 1);

    return max(case1, case2);
}