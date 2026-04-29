#include <vector>
#include<queue>
#include<algorithm>
#include<limits.h>

using namespace std;

bool onSide(const vector<int>& _rect, int cX, int cY)
{
	int x1 = min(_rect[0], _rect[2]);
	int x2 = max(_rect[0], _rect[2]);
	int y1 = min(_rect[1], _rect[3]);
	int y2 = max(_rect[1], _rect[3]);

	if (x1 == cX || x2 == cX)
	{
		if (y1 <= cY && cY <= y2)
		{
			return true;
		}
	}

	if (y1 == cY || y2 == cY)
	{
		if (x1 <= cX && cX <= x2)
		{
			return true;
		}
	}

	return false;
}

bool inRect(const vector<int>& _rect, int cX, int cY)
{
	int x1 = min(_rect[0], _rect[2]);
	int x2 = max(_rect[0], _rect[2]);
	int y1 = min(_rect[1], _rect[3]);
	int y2 = max(_rect[1], _rect[3]);

	if (x1 < cX && cX < x2 &&
		y1 < cY && cY < y2)
		return true;

	return false;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	int answer = INT_MAX;
	const int dirSize = 4;
	const int maxValueLimit = 102;

	vector<vector<bool>> visited(maxValueLimit, vector<bool>(maxValueLimit, false));

	for (int i = 0; i < rectangle.size(); i++)
	{
		for (int j = 0; j < rectangle[i].size(); j++)
		{
			rectangle[i][j] *= 2;
		}
	}

	characterX *= 2;
	characterY *= 2;
	itemX *= 2;
	itemY *= 2;

	const int dir[dirSize][2] = { {-1,0},{1,0}, {0,-1},{0,1} };

	struct Pos
	{
		int x = 0;
		int y = 0;
		int cost = 0;
		Pos(int x, int y, int cost) : x(x), y(y), cost(cost) {}
	};

	queue<Pos> q;
	q.push(Pos(characterX, characterY, 0));

	while (q.empty() == false)
	{
		Pos p = q.front();
		q.pop();

		int nowX = p.x;
		int nowY = p.y;
		int nowCost = p.cost;

		// 목적지인 경우는 값 체크만 해주고 continue
		if (nowX == itemX &&
			nowY == itemY)
		{
			answer = nowCost;
			break;
		}

		// 이미 방문함
		if (visited[nowX][nowY] == true)
			continue;

		// 사각형 안에 있는지를 체크
		bool isInRect = false;
		for (const auto& r : rectangle)
		{
			if (inRect(r, nowX, nowY) == true)
			{
				isInRect = true;
				break;
			}
		}

		// 다른 사각형 안에 있는 경우이다
		if (isInRect == true)
			continue;

		bool isOnSide = false;
		for (const auto& r : rectangle)
		{
			// 내부 경계선으로 들어가면 안된다
			if (onSide(r, nowX, nowY) == true)
			{
				isOnSide = true;
				break;
			}
		}

		// 테두리에 없는 상황이다
		if (isOnSide == false)
			continue;

		visited[nowX][nowY] = true;

		for (int i = 0; i < dirSize; i++)
		{
			int dx = nowX + dir[i][0];
			int dy = nowY + dir[i][1];
			int nextCost = nowCost + 1;

			if (dx < 0 || dx > maxValueLimit ||
				dy < 0 || dy > maxValueLimit)
				continue;

			q.push(Pos(dx, dy, nextCost));
		}
	}

	answer /= 2;

	return answer;
}