#include <string>
#include <vector>
#include <queue>

using namespace std;

// 아래
// 좌
// 우
// 위
const string dirCom[4] = { "d","l" ,"r" ,"u" };

void solution(int n, int m, int x, int y, int r, int c, int k, string& answer, string nowCom)
{
	// 정답에 도달
	if (k == 0 && x == r && y == c)
	{
		answer = nowCom;
		return;
	}
	else 
	{
		// 이미 k 개수가 
		if (k <= 0)
		{
			answer = "impossible";
			return;
		}
		
		// abs(x - r) + abs( y - c) 의 값이 k보다 큰 상황
        // 이쪽 루트로는 뭘 해도 도달 불가하다
        int remain = abs(x - r) + abs(y - c);
        if (remain > k ||
            (remain % 2 == 1 && k % 2 == 0))
        {
            answer = "impossible";
            return;
        }
	}

	// 범위 벗어남
	if (x < 0 || x >= n ||
		y < 0 || y >= m)
	{
		return;
	}

	// 아래
	if (answer == "" || answer == "impossible")
	{
		solution(n, m, x + 1, y, r, c, k - 1, answer, nowCom + dirCom[0]);
	}

	// 좌
	if (answer == "" || answer == "impossible")
	{
		solution(n, m, x, y - 1, r, c, k - 1, answer, nowCom + dirCom[1]);
	}

	// 우
	if (answer == "" || answer == "impossible")
	{
		solution(n, m, x, y + 1, r, c, k - 1, answer, nowCom + dirCom[2]);
	}

	// 위
	if (answer == "" || answer == "impossible")
	{
		solution(n, m, x - 1, y, r, c, k - 1, answer, nowCom + dirCom[3]);
	}

}

string solution(int n, int m, int x, int y, int r, int c, int k) {
	string answer = "";

	// 어차피 모든 경로를 다 뒤져야 한다면
	// dfs가 오히려 빨리 찾을 수 있지 않을까?
	// 이건 조건에 맞는 가장 '적은 수'를 찾는 것이기에
	solution(n, m, x - 1, y - 1, r - 1, c - 1, k, answer, "");

	return answer;
}