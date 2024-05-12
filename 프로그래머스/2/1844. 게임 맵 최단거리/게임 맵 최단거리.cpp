#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<vector<int> > maps)
{
	// 0,0 부터 maps(m x n)의 m,n 위치에 도달하려는 가장 짧은 크기
	// 도달 불가 시 -1
	int answer = -1;

	const pii dir[4] = {
	{ 1,0},	// right
	{ -1,0,},	// left
	{ 0,1, },// down
	{ 0,-1 }// up
	};

	int height = maps.size();
	int width = maps[0].size();

	struct loadInfos
	{
		int x = 0;
		int y = 0;
		int cost = 0;
		loadInfos(int x,int y, int cost) : x(x),y(y),cost(cost) {}
	};

	// bfs 이기에 queue로 풀 예정
	queue<loadInfos> q;
	q.push(loadInfos(0,0,0));

	while (q.empty() == false)
	{
		loadInfos l = q.front();
		q.pop();

		// 범위를 넘어섬
		if (l.x >= width || l.x < 0 ||
			l.y >= height || l.y < 0)
			continue;

		// 해당 길은 막혀 있음
		if (maps[l.y][l.x] == 0)
			continue;

		if (l.x == width - 1 && l.y == height - 1)
		{
			if (answer == -1)
			{
				answer = INT_MAX;
			}

			answer = min(answer, l.cost + 1);
			continue;
		}

		maps[l.y][l.x] = 0; // visited 대신 이걸 사용하기 - bfs 탐색은 항상 최단 거리를 찾을 수 있으므로

		for (int i = 0; i < 4; i++)
		{
			const pii& d = dir[i];

			q.push(loadInfos(l.x + d.first, l.y + d.second, l.cost + 1));
		}
	}

	return answer;
}