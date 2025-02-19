#include <vector>

using namespace std;

int nums[101][101] = { 0 };

int solution(int n, int w, int num) {
	int answer = 1;
	int nextFind = num;
	bool isRight = true;

	int idx = 1;
	for (int i = 1; i <= n / w + 1; i++)
	{
		if (isRight)
		{
			for (int j = 1; j <= w; j++)
			{
				nums[i][j] = idx;
				if (nums[i - 1][j] == nextFind)
				{
					answer++;
					nextFind = idx;
				}

				idx++;
				if (idx > n)
					return answer;
			}
		}
		else
		{
			for (int j = w; j > 0; j--)
			{
				nums[i][j] = idx;
				if (nums[i - 1][j] == nextFind)
				{
					answer++;
					nextFind = idx;
				}

				idx++;
				if (idx > n)
					return answer;
			}
		}

		isRight = !isRight;
	}

	return answer;
}