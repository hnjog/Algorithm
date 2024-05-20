#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {

	// 인접 행렬 + 플로이드-워셜
	// i가 j를 이겼다면 vector<vector<bool>> 에서 [i][j] = true
	// 특정한 '선수'의 모든 승패 여부의 값이 n - 1인지 확인하기
	// (+ 간접적인 경로 계산 역시 필요함) 
	vector<vector<bool>> g(n, vector<bool>(n, false));

	for (const auto& r : results)
	{
		int win = r[0] - 1;
		int lose = r[1] - 1;
		g[win][lose] = true;
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// 반복문을 돌면서
				// 승패를 덮어씌움
				if (g[i][k] == true && g[k][j] == true)
				{
					g[i][j] = true;
				}
			}
		}
	}

	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (g[i][j] == true)
				count++;
			if (g[j][i] == true)
				count++;
		}

		if (count == n - 1)
			answer++;
	}

	return answer;
}