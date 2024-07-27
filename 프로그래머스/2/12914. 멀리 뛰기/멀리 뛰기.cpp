using namespace std;

int dp[2001];
const int d = 1234567;

int recur(int target)
{
    if (target < 0)
        return 0;

    if (target <= 2)
    {
        return target;
    }

    if (dp[target])
    {
        return dp[target] % d;
    }

    return dp[target] = (recur(target - 1) + recur(target - 2)) % d;
}

long long solution(int n) {

    return recur(n) % d;
}