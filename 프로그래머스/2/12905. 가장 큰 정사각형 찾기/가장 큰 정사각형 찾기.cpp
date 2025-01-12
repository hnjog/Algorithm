#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
	int h = board.size();
	int w = board[0].size();
	vector<vector<int>> sum(h + 1, vector<int>(w + 1, 0));

	// 누적합 계산
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			sum[i][j] = board[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	int maxSize = min(h, w);

	for (int nowSize = maxSize; nowSize >= 1; nowSize--)
	{
		for (int i = 0; i <= h - nowSize; i++)
		{
			for (int j = 0; j <= w - nowSize; j++)
			{
				int squareSum = sum[i + nowSize][j + nowSize] - sum[i][j + nowSize] - sum[i + nowSize][j] + sum[i][j];

				if (squareSum == nowSize * nowSize)
				{
					return nowSize * nowSize;
				}
			}
		}
	}
    
    return 0;
}