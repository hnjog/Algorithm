#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	vector<vector<bool>> winCheck(n, vector<bool>(n, false));

	for (vector<int>& r : results)
	{
		int a = r[0] - 1;
		int b = r[1] - 1;
		// a가 b를 이김
		winCheck[a][b] = true;
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// i 가 k를 이기고
				// k 가 j를 이겼다면
				if (winCheck[i][k] &&
					winCheck[k][j])
				{
					winCheck[i][j] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		bool bCheck = true;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;

			// 두 사람간 승패가 명확하지 않음 -> 정답 아님
			if (winCheck[i][j] == false &&
				winCheck[j][i] == false)
			{
				bCheck = false;
				break;
			}
		}

		if (bCheck)
			answer++;
	}

	return answer;
}