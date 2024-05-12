#include <string>
#include <vector>

using namespace std;

int dp(int x, int y, int m, int n,const vector<vector<bool>>& p , vector<vector<int>>& memo)
{
	if (x > m)
		return 0;

	if (y > n)
		return 0;

	if (p[x][y])
		return 0;

	if (memo[x][y] != 0)
		return memo[x][y];

	if (x == m && y == n)
		return 1;

	return memo[x][y] = (dp(x + 1, y, m, n, p, memo) + dp(x, y + 1, m, n, p, memo)) % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
	vector<vector<bool>> p(vector<vector<bool>>(m + 1, vector<bool>(n + 1, false)));
	vector<vector<int>> memo(vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

	int width = puddles.size();

	for (int i = 0; i < width; i++)
	{
		int xValue = puddles[i][0];
		int yValue = puddles[i][1];

		p[xValue][yValue] = true;
	}

	int answer = dp(1, 1, m, n, p,memo);

	return answer % 1000000007;
}
