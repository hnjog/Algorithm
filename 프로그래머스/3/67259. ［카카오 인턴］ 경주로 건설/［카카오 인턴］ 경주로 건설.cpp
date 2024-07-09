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
	const int n = board.size() - 1;
	int answer = 0;
	struct wayInfo
	{
		int y = 0;
		int x = 0;

		dir d = down;

		int f = 1;
		int c = 0;
	};

	queue<wayInfo> q;
	q.push(wayInfo());
	q.push({ 0,0,right });

	vector<vector<pair<int, int>>> dp1(n + 1, vector<pair<int, int>>(n + 1, { INT_MAX / 10 ,INT_MAX / 10 })); // up, down 상황일때 비교
	vector<vector<pair<int, int>>> dp2(dp1);   // left, right 상황일때 비교

	while (q.empty() == false)
	{
		wayInfo now = q.front();
		q.pop();
		int size = q.size();

		if (now.x < 0 || now.x > n ||
			now.y < 0 || now.y > n)
			continue;

		if (board[now.y][now.x] == 1)
			continue;

		if (now.d == up || now.d == down)
		{
			int cost = now.f + now.c * 5;
			int dCost = dp1[now.y][now.x].first + dp1[now.y][now.x].second * 5;
			if (cost >= dCost)
				continue;

			dp1[now.y][now.x] = {now.f,now.c};
		}
		else
		{
			int cost = now.f + now.c * 5;
			int dCost = dp2[now.y][now.x].first + dp2[now.y][now.x].second * 5;
			if (cost >= dCost)
				continue;

			dp2[now.y][now.x] = { now.f,now.c };
		}

		if (now.x == n &&
			now.y == n)
		{
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

			q.push(wayInfo{ nextY,nextX,static_cast<dir>(nextDir),nextF,nextC });
		}

	}



	answer = min(dp1[n][n].first + dp1[n][n].second * 5 - 1, dp2[n][n].first + dp2[n][n].second * 5 - 1);
	answer *= 100;

	return answer;
}