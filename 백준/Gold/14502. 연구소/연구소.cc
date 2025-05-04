#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

struct pos
{
	int y, x;
};

int h, w;
int maxV = 0;
int remainZero = 0;

void getCount(vector<vector<int>> map, vector<pos>& virusPos)
{
	vector<vector<bool>> visited(h, vector<bool>(w, false));

	int rZ = remainZero - 3;

	queue<pos> q;
	for (pos p : virusPos)
	{
		q.push({ p.y + 1,p.x });
		q.push({ p.y - 1,p.x });
		q.push({ p.y ,p.x + 1 });
		q.push({ p.y ,p.x - 1 });
	}

	while (q.empty() == false)
	{
		int nowY = q.front().y;
		int nowX = q.front().x;
		q.pop();

		if (nowY < 0 || nowX < 0 ||
			nowY >= h || nowX >= w)
			continue;

		if (map[nowY][nowX] != 0 ||
			visited[nowY][nowX])
			continue;

		visited[nowY][nowX] = true;
		map[nowY][nowX] = 2;
		rZ--;
		if (rZ <= maxV)
			return;

		q.push({ nowY + 1,nowX });
		q.push({ nowY - 1,nowX });
		q.push({ nowY ,nowX + 1 });
		q.push({ nowY ,nowX - 1 });
	}

	if (maxV < rZ)
		maxV = rZ;
}

void setWalls(vector<vector<int>>& map, vector<pos>& virusPos, vector<pos>& zeroPlace)
{
	int zSize = zeroPlace.size();
	for (int i = 0; i < zSize;i++)
	{
		pos p = zeroPlace[i];
		int y = p.y;
		int x = p.x;
		map[y][x] = 1;

		for (int j = i + 1; j < zSize; j++)
		{
			pos p2 = zeroPlace[j];
			int y2 = p2.y;
			int x2 = p2.x;
			map[y2][x2] = 1;
			for (int k = j + 1; k < zSize; k++)
			{
				pos p3 = zeroPlace[k];
				int y3 = p3.y;
				int x3 = p3.x;
				map[y3][x3] = 1;
				getCount(map, virusPos);
				map[y3][x3] = 0;
			}
			map[y2][x2] = 0;
		}
		map[y][x] = 0;
	}
}

int main()
{

	cin >> h >> w;
	vector<vector<int>> map(h, vector<int>(w, 0));

	vector<pos> virusPos, zeroPlace;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int t;
			cin >> t;
			map[i][j] = t;
			if (t == 2)
				virusPos.push_back({ i,j });

			if (t == 0)
			{
				remainZero++;
				zeroPlace.push_back({ i,j });
			}
		}
	}

	setWalls(map, virusPos, zeroPlace);

	cout << maxV;
}