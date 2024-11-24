#include<vector>

using namespace std;

int solution(vector<vector<int>> board)
{
	// dp[i][j] : i,j 를 오른쪽 하단으로 하는 정사각형의 크기
	const size_t h = board.size();
	const size_t w = board[0].size();
	
	vector<vector<int>> dp = board;

	for (size_t i = 1; i < h; i++)
	{
		for (size_t j = 1; j < w; j++)
		{
            if (dp[i][j] != 0 &&
                dp[i - 1][j] != 0 &&
                dp[i][j - 1] != 0 &&
                dp[i - 1][j - 1] != 0)
            {
				int v1 = dp[i - 1][j];
				int v2 = dp[i][j - 1];
				int v3 = dp[i - 1][j - 1];

				int minV = min(v1, min(v2, v3));
				dp[i][j] = minV + 1;
            }
		}
	}

	int answer = 0;

	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			if (answer < dp[i][j])
				answer = dp[i][j];
		}
	}

	answer *= answer;

	return answer;
}