#include<iostream>
#include<vector>

using namespace std;

enum dir
{
	d_Up = 0,
	d_Right,
	d_Down,
	d_Left
};

const int dirY[4] = { -1,0,1,0 };
const int dirX[4] = { 0, 1,0,-1 };

class Robot
{
public:
	Robot(int y, int x, int d)
		:posY(y),
		posX(x),
		nowDir(d),
		amount(0)
	{
	}

	int Work(vector<vector<int>>& maps)
	{
		int n = maps.size();
		int m = maps[0].size();

		while (true)
		{
			// 현재 칸이 청소되지 않은 경우 청소
			if (maps[posY][posX] == 0)
			{
				amount++;
				maps[posY][posX] = 2;
				continue;
			}

			if (SearchNonClear(maps) == false)
			{
				if (CheckBack(maps))
				{
					// 후진 가능
					posY -= dirY[nowDir];
					posX -= dirX[nowDir];
				}
				else
				{
					// 후진 못하면 작동 정지
					break;
				}
			}
			else // 주변 4칸에 청소되지 않은 빈칸 존재
			{
				nowDir--;
				if (nowDir < 0)
					nowDir = d_Left;

				// 정면 한칸 체크
				if (CheckFront(maps))
				{
					// 더럽다면 전진
					posY += dirY[nowDir];
					posX += dirX[nowDir];
				}
			}
		}

		return amount;
	}

protected:
	bool SearchNonClear(vector<vector<int>>& map)
	{
		int n = map.size();
		int m = map[0].size();

		for (int i = 0; i <= d_Left; i++)
		{
			int ny = posY + dirY[i];
			int nx = posX + dirX[i];

			if (ny < 0 || ny >= n ||
				nx < 0 || nx >= m)
				continue;

			if (map[ny][nx] == 0)
				return true;
		}

		return false;
	}

	bool CheckFront(vector<vector<int>>& map)
	{
		int n = map.size();
		int m = map[0].size();

		int ny = posY+ dirY[nowDir];
		int nx = posX+ dirX[nowDir];
		
		if (map[ny][nx] == 0)
			return true;
		
		return false;
	}

	bool CheckBack(vector<vector<int>>& map)
	{
		int n = map.size();
		int m = map[0].size();

		int ny = posY - dirY[nowDir];
		int nx = posX - dirX[nowDir];

		if (map[ny][nx] == 1)
			return false;

		return true;
	}

protected:
	int posY;
	int posX;
	int nowDir;
	int amount;
};

int main()
{
	int n, m;
	cin >> n >> m;

	int y, x, d;
	cin >> y >> x >> d;

	Robot robot(y, x, d);

	vector<vector<int>> map(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	cout << robot.Work(map);
	return 0;
}