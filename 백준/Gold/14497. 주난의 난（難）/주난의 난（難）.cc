#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct Infos
{
	int y, x, cost;
};

struct Compare
{
	bool operator()(Infos& a, Infos& b)
	{
		return a.cost > b.cost;
	}
};

int sy, sx, ty, tx;

int dirY[4] = { 0,-1,0,1 };
int dirX[4] = { -1,0,1,0 };

int getV(vector<string>& str)
{
	int n = str.size();
	int m = str[0].size();

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	priority_queue<Infos, vector<Infos>, Compare> pq;

	pq.push({ sy,sx,0 });

	while (pq.empty() == false)
	{
		int ny = pq.top().y;
		int nx = pq.top().x;
		int ncost = pq.top().cost;
		pq.pop();

		if (visited[ny][nx])
			continue;

		visited[ny][nx] = true;

		if (ny == ty &&
			nx == tx)
			return ncost + 1;

		for (int i = 0; i < 4; i++)
		{
			int nextY = ny + dirY[i];
			int nextX = nx + dirX[i];
			int nextC = ncost;

			if (nextY < 0 || nextY >= n ||
				nextX < 0 || nextX >= m)
				continue;

			if (str[nextY][nextX] == '1')
				nextC++;

			pq.push({ nextY,nextX,nextC });
		}
	}

}

int main()
{
	// 시작 지점에서 4방향으로 퍼짐
	// 목표값이 쓰러질때의 cost 반환

	int n, m;
	cin >> n >> m;

	cin >> sy >> sx >> ty >> tx;
	sy--;
	sx--;
	ty--;
	tx--;

	vector<string> str(n);

	for (int i = 0; i < n; i++)
		cin >> str[i];

	cout << getV(str);

	return 0;
}