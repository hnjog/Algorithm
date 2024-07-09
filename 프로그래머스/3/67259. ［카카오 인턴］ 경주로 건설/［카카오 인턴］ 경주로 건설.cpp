#include <vector>
#include<queue>
#include<limits.h>

using namespace std;

enum dir
{
	down = 0,
	right,
	up,
	left,
};

int solution(vector<vector<int>> board) {
	// bfs 처럼 보임
	// 그러나 장애물 존재
	// + 전진이 아닌 경우 추가 비용

	const int n = board.size() - 1;
	int answer = 0;
	struct wayInfo
	{
		int y = 0;
		int x = 0;

		dir d = down;
		int cost = 100;

		int f = 1;
		int c = 0;
	};

	queue<wayInfo> q;
	q.push(wayInfo());
	q.push({ 0,0,right,100 });

	vector<vector<int>> dp1(n + 1, vector<int>(n + 1, INT_MAX)); // up, down 상황일때 비교
	vector<vector<int>> dp2(dp1);   // left, right 상황일때 비교

	while (q.empty() == false)
	{
		wayInfo now = q.front();
		q.pop();

		if (now.x < 0 || now.x > n ||
			now.y < 0 || now.y > n)
			continue;

		if (board[now.y][now.x] == 1)
			continue;

		if (now.d == up || now.d == down)
		{
			if (now.cost >= dp1[now.y][now.x])
				continue;

			dp1[now.y][now.x] = now.cost;
		}
		else
		{
			if (now.cost >= dp2[now.y][now.x])
				continue;

			dp2[now.y][now.x] = now.cost;
		}

		if (now.x == n &&
			now.y == n)
		{
			int finalCost = (now.f - 1) * 100 + now.c * 500;

			if (now.d == up || now.d == down)
			{
				dp1[now.y][now.x] = finalCost;
			}
			else
			{
				dp2[now.y][now.x] = finalCost;
			}

			continue;
		}

		// 직진, 좌회전, 우회전
		for (int i = 0; i < 3; i++)
		{
			int nextDir = now.d;
			int nextF = now.f + 1;
			int nextC = now.c;

			if (i == 1)
			{
				nextDir--;
				if (nextDir < 0)
					nextDir = left;

				nextC++;
			}

			if (i == 2)
			{
				nextDir++;
				if (nextDir > left)
					nextDir = down;

				nextC++;
			}

			int nextX = now.x;
			int nextY = now.y;

			switch (nextDir)
			{
			case down:
				nextY++;
				break;
			case right:
				nextX++;
				break;
			case up:
				nextY--;
				break;
			case left:
				nextX--;
				break;
			}


			int nextCost = now.cost + 100;
			if (i != 0)
			{
				nextCost += 400;
			}

			q.push(wayInfo{ nextY,nextX,static_cast<dir>(nextDir),nextCost,nextF,nextC });
		}

	}

	answer = min(dp1[n][n], dp2[n][n]);

	return answer;
}