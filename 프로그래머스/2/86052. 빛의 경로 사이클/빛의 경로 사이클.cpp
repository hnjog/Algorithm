#include <string>
#include <vector>
#include<algorithm>

using namespace std;

const int dirSize = 4;
const int dirY[dirSize] = { -1,0,1,0 };
const int dirX[dirSize] = { 0,1,0,-1 };

struct node
{
	char c;
	int y;
	int x;
	vector<bool> visit;
};

void dfs(vector<vector<node>>& maps, vector<int>& answer, int dir,int startY,int startX, int nowY,int nowX, int count)
{
	// 이미 해당 노드에서 방문한 방향
	if (maps[nowY][nowX].visit[dir])
	{
		// 시작 노드이다
		if (nowY == startY &&
			nowX == startX &&
			count != 0)
		{
			answer.push_back(count);
		}
		return;
	}

	maps[nowY][nowX].visit[dir] = true;

	char d = maps[nowY][nowX].c;
	int nextDir = dir;
	int nextY = nowY;
	int nextX = nowX;

	switch (d)
	{
	case 'S':
	{
		nextY = nowY + dirY[nextDir];
		if (nextY < 0)
			nextY = maps.size() - 1;
		else if (nextY >= maps.size())
			nextY = 0;

		nextX = nowX + dirX[nextDir];
		if (nextX < 0)
			nextX = maps[nextY].size() - 1;
		else if (nextX >= maps[nextY].size())
			nextX = 0;

	}
		break;
	case 'L':
	{
		nextDir--;
		if (nextDir < 0)
			nextDir = dirSize - 1;

		nextY = nowY + dirY[nextDir];
		if (nextY < 0)
			nextY = maps.size() - 1;
		else if (nextY >= maps.size())
			nextY = 0;

		nextX = nowX + dirX[nextDir];
		if (nextX < 0)
			nextX = maps[nextY].size() - 1;
		else if (nextX >= maps[nextY].size())
			nextX = 0;

	}
	break;
	case 'R':
	{
		nextDir++;
		if (nextDir >= dirSize)
			nextDir = 0;

		nextY = nowY + dirY[nextDir];
		if (nextY < 0)
			nextY = maps.size() - 1;
		else if (nextY >= maps.size())
			nextY = 0;

		nextX = nowX + dirX[nextDir];
		if (nextX < 0)
			nextX = maps[nextY].size() - 1;
		else if (nextX >= maps[nextY].size())
			nextX = 0;

	}
	break;
	}

	dfs(maps, answer, nextDir, startY, startX, nextY, nextX, count + 1);
}

void RecurStart(vector<vector<node>>& maps, vector<int>& answer)
{
	for (auto& m : maps)
	{
		for (auto& no : m)
		{
			for (int i = 0; i < dirSize; i++)
				dfs(maps, answer, i, no.y, no.x, no.y, no.x, 0);
		}
	}

	sort(answer.begin(), answer.end());
}

vector<int> solution(vector<string> grid) {
	vector<int> answer;
	vector<vector<node>> maps(grid.size(), vector<node>(grid[0].size()));

	for (int y = 0; y < grid.size(); y++)
	{
		for (int x = 0; x < grid[y].size(); x++)
		{
			maps[y][x] = { grid[y][x],y,x};
			maps[y][x].visit = vector<bool>(dirSize, false);
		}
	}

	RecurStart(maps, answer);
	return answer;
}