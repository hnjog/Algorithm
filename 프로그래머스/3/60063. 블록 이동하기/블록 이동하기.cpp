#include <vector>
#include<queue>
#include<limits.h>

using namespace std;

struct info
{
	// 좌측 혹은 상단
	int y1 = 0;
	int x1 = 0;

	// 우측 혹은 하단
	int y2 = 0;
	int x2 = 1;

	// 이동 시간
	int cost = 0;
};

bool isGoal(const vector<vector<int>>& board,const info& i)
{
	const int goal = board.size() - 1;
	if (i.x1 == goal &&
		i.y1 == goal)
		return true;

	if (i.x2 == goal &&
		i.y2 == goal)
		return true;

	return false;
}

bool isInBoard(const vector<vector<int>>& board, const info& i)
{
	const int n = board.size();

	if (i.x1 >= n ||
		i.x1 < 0 ||
		i.y1 < 0 ||
		i.y1 >= n)
		return false;

	if (i.x2 >= n ||
		i.x2 < 0 ||
		i.y2 < 0 ||
		i.y2 >= n)
		return false;

	return true;
}

bool isRotate(const vector<vector<int>>& board, info& i, bool isWide)
{
	const int n = board.size();

	if (i.x1 + 1 >= n ||
		i.x1 + 1 < 0 ||
		i.y1 + 1 < 0 ||
		i.y1 + 1 >= n)
		return false;

	// - 모양이라면
	if (isWide)
	{
		// x1 , y1을 회전하되
		// x1, y1 + 1 과 x1 + 1, y1 + 1이 모두 0이여야 함
		if (board[i.y1 + 1][i.x1] == 1 ||
			board[i.y1 + 1][i.x1 + 1] == 1)
			return false;

		// - 에서 첫번쨰가 2번쨰 위치로
		// 2번째 녀석은 y축으로 한칸 내려옴
		i.x1 = i.x2;
		i.y1 = i.y2;

		i.y2 += 1;

		return true;
	}

	// | 모양이라면
	// x1,y1 녀석을 x1 + 1, y1 + 1으로 옮겨야 하는 상황
	//
	if (board[i.y1][i.x1 + 1] == 1 ||
		board[i.y1 + 1][i.x1 + 1] == 1)
		return false;

	i.x1 = i.x2;
	i.y1 = i.y2;

	i.x2 += 1;

	return true;
}

bool isRotate2(const vector<vector<int>>& board, info& i, bool isWide)
{
	const int n = board.size();

	// - 모양이라면
	if (isWide)
	{
		if (i.x1 + 1 >= n ||
			i.x1 + 1 < 0 ||
			i.y1 - 1 < 0 ||
			i.y1 - 1 >= n)
			return false;

		if (board[i.y1 - 1][i.x1] == 1 ||
			board[i.y1 - 1][i.x1 + 1] == 1)
			return false;

		i.x1 = i.x2;
		i.y1 = i.y2 - 1;

		return true;
	}

	if (i.x1 + 1 >= n ||
		i.x1 + 1 < 0 ||
		i.y1 + 1 < 0 ||
		i.y1 + 1 >= n)
		return false;

	// | 라면
	if (board[i.y1][i.x1 + 1] == 1 ||
		board[i.y1 + 1][i.x1 + 1] == 1)
		return false;

	i.x2 = i.x1 + 1;
	i.y2 = i.y1;

	return true;
}

bool isRotate3(const vector<vector<int>>& board, info& i, bool isWide)
{
	const int n = board.size();

	// - 모양이라면
	if (isWide)
	{
		if (i.x1 + 1 >= n ||
			i.x1 + 1 < 0 ||
			i.y1 - 1 < 0 ||
			i.y1 - 1 >= n)
			return false;

		if (board[i.y1 - 1][i.x1] == 1 ||
			board[i.y1 - 1][i.x1 + 1] == 1)
			return false;

		i.x2 = i.x1;
		i.y2 = i.y1;

		i.y1 -= 1;

		return true;
	}

	if (i.x1 - 1 >= n ||
		i.x1 - 1 < 0 ||
		i.y1 + 1 < 0 ||
		i.y1 + 1 >= n)
		return false;

	// | 라면
	if (board[i.y1][i.x1 - 1] == 1 ||
		board[i.y1 + 1][i.x1 - 1] == 1)
		return false;

	i.x1 = i.x1 - 1;
	i.y1 = i.y2;

	return true;
}

bool isRotate4(const vector<vector<int>>& board, info& i, bool isWide)
{
	const int n = board.size();

	// - 모양이라면
	if (isWide)
	{
		if (i.x1 + 1 >= n ||
			i.x1 + 1 < 0 ||
			i.y1 + 1 < 0 ||
			i.y1 + 1 >= n)
			return false;

		if (board[i.y1 + 1][i.x1] == 1 ||
			board[i.y1 + 1][i.x1 + 1] == 1)
			return false;

		i.x2 = i.x1;
		i.y2 = i.y1 + 1;

		return true;
	}

	if (i.x1 - 1 >= n ||
		i.x1 - 1 < 0 ||
		i.y1 + 1 < 0 ||
		i.y1 + 1 >= n)
		return false;

	// | 라면
	if (board[i.y1][i.x1 - 1] == 1 ||
		board[i.y1 + 1][i.x1 - 1] == 1)
		return false;

	i.x2 = i.x1;
	i.y2 = i.y1;

	i.x1 -= 1;

	return true;
}

int solution(vector<vector<int>> board) {
	const int n = board.size();
	int answer = 0;
	queue<info> q;
	q.push(info());

	const int dx[4] = { 1,0, -1, 0 };
    const int dy[4] = { 0,1, 0, -1 };
	vector<vector<int>> dpWide(n,vector<int>(n,INT_MAX)); // - 모양 dp
	vector<vector<int>> dpSide(n,vector<int>(n,INT_MAX)); // | 모양 dp

	while (q.empty() == false)
	{
		auto now = q.front();
		q.pop();
		bool isWide = (now.x1 == now.x2) ? false: true; // 

		// 블럭이 좌표를 벗어난 경우이다
		if (isInBoard(board, now) == false)
		{
			continue;
		}

		// 이미 해당 모양이 now의 x1,y1에 해당하는 지점에 도착하였고 더 적은 값이다
		if (isWide)
		{
			if (dpWide[now.y1][now.x1] <= now.cost)
				continue;

			dpWide[now.y1][now.x1] = now.cost;
		}
		else
		{
			if (dpSide[now.y1][now.x1] <= now.cost)
				continue;

			dpSide[now.y1][now.x1] = now.cost;
		}

		if (isGoal(board, now))
		{
			answer = now.cost;
			break;
		}

		{
			// 그대로 진행
			for (int i = 0; i < 4; i++)
			{
				info next = { now.y1 + dy[i], now.x1 + dx[i],now.y2 + dy[i],now.x2 + dx[i],now.cost + 1 };

				if (isInBoard(board, next) == false)
					continue;

				// 블럭이 끼는 상황이다
				if (board[next.y1][next.x1] == 1 ||
					board[next.y2][next.x2] == 1)
					continue;

				q.push(next);
			}
		}

		{
			// | 모양이므로
			// -> 하여 모양 잡기
			// x2의 x1,x2를 바꾸어 주기
			info copyNow = now;
			if (isRotate(board, copyNow, isWide))
			{
				copyNow.cost += 1;
				q.push(copyNow);
			}

			copyNow = now;
			if (isRotate2(board, copyNow, isWide))
			{
				copyNow.cost += 1;
				q.push(copyNow);
			}

			copyNow = now;
			if (isRotate3(board, copyNow, isWide))
			{
				copyNow.cost += 1;
				q.push(copyNow);
			}

			copyNow = now;
			if (isRotate4(board, copyNow, isWide))
			{
				copyNow.cost += 1;
				q.push(copyNow);
			}
		}
	}

	return answer;
}
