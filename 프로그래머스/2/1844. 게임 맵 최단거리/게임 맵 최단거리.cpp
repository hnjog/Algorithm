#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

const int dirY[4] = { 0,-1,0,1 };
const int dirX[4] = { -1,0,1,0 };

struct pos
{
	int y, x, cost;
};

int solution(vector<vector<int>> maps)
{
	int answer = -1;

	int h = maps.size();
	int w = maps[0].size();

	vector<vector<int>> visited(h, vector<int>(w, INT_MAX));

	queue<pos> q;
	q.push({ 0,0,1 });

	while (q.empty() == false)
	{
		int nowy = q.front().y;
		int nowx = q.front().x;
		int nowc = q.front().cost;
		q.pop();

		if (nowy == h - 1 &&
			nowx == w - 1)
		{
			answer = nowc;
			break;
		}

		if (nowy < 0 || nowy >= h ||
			nowx < 0 || nowx >= w)
			continue;

		if (maps[nowy][nowx] == 0)
			continue;

		if (nowc >= visited[nowy][nowx])
			continue;

		visited[nowy][nowx] = nowc;

		for (int i = 0; i < 4; i++)
		{
			int ny = nowy + dirY[i];
			int nx = nowx + dirX[i];
			q.push({ ny,nx,nowc + 1 });
		}
	}

	return answer;
}