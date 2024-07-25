#include <vector>

using namespace std;

int dp[100001];
const int d = 1234567;

int fibo(int n)
{
    if(n <= 1)
        return n;
    
    if(dp[n] != 0)
        return dp[n] % d;
    
    return dp[n] = (fibo(n - 1)%d) + (fibo(n - 2)%d);
}

int solution(int n) {
    return fibo(n) % d;
}