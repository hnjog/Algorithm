#include<iostream>
#include<queue>
#include<memory.h>
#include<limits.h>

using namespace std;

int n;
int map[21][21];

int bSize = 2;
int bCount = 0;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1 ,0 };

struct Pos
{
	int y, x;
	int cost;
};

Pos bSets(int startY, int startX, int& cost)
{
	// 찾을 수 없다면 -1,-1 을 return
	queue<Pos> q;
	q.push({ startY,startX,0 });

	Pos target = { -1,-1,INT_MAX };
	bool visit[21][21];
	memset(visit, false, sizeof(visit));

	while (q.empty() == false)
	{
		int nowY = q.front().y;
		int nowX = q.front().x;
		int nowCost = q.front().cost;
		q.pop();

		if (nowY < 0 || nowX < 0 ||
			nowY >= n || nowX >= n)
			continue;

		if (map[nowY][nowX] >= 1 && map[nowY][nowX] <= 6)
		{
			// 자신보다 크기가 큰 물고기는 통과하지 못함
			if (map[nowY][nowX] > bSize)
				continue;

			// 자기 크기 이상을 먹을순 없음
			if (map[nowY][nowX] < bSize)
			{
				if ((nowCost < target.cost) || // 더 저렴
					(nowCost == target.cost && (nowY < target.y)) || // 비용 같은데 위쪽 존재
					(nowCost == target.cost && (nowY == target.y) && (nowX < target.x))) // 비용도 같고 위쪽도 같다면 왼쪽에 있는것
				{
					target = { nowY,nowX,nowCost };
				}
			}
		}

		if (visit[nowY][nowX])
			continue;

		visit[nowY][nowX] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dirY[i];
			int nextX = nowX + dirX[i];
			q.push({ nextY,nextX,nowCost + 1 });
		}
	}

	if (target.cost != INT_MAX)
	{
		cost += target.cost;
		map[startY][startX] = 0;

		bCount++;
		if (bCount == bSize)
		{
			bSize++;
			bCount = 0;
		}

		map[target.y][target.x] = 9;
	}

	return target;
}

int main()
{
	cin >> n;

	int sy = 0, sx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int t;
			cin >> t;
			map[i][j] = t;
			if (t == 9)
			{
				sy = i;
				sx = j;
			}
		}
	}

	int cost = 0;
	while (true)
	{
		Pos p = bSets(sy, sx, cost);
		if (p.y == -1 && p.x == -1)
			break;

		sy = p.y;
		sx = p.x;
	}

	cout << cost;
}