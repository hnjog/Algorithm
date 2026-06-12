#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct pos
{
	int y, x;
};

int CheckingRoad(const vector<vector<int>>& maps, int startY,int startX)
{
	queue<pos> q;
	q.push({ startY,startX });

	const int lim = 100;
	vector<vector<bool>> visit(lim, vector<bool>(lim,false));

	while (q.empty() == false)
	{
		int nowY = q.front().y;
		int nowX = q.front().x;
		q.pop();

		if (nowX < 0 || nowX >= lim ||
			nowY < 0 || nowY >= lim)
			continue;

		if (maps[nowY][nowX] == 0)
			continue;

		if (nowY == 0)
			return nowX;

		if (visit[nowY][nowX] == true)
			continue;

		visit[nowY][nowX] = true;

		bool bUp = true;

		if (nowX >= 1 &&
			maps[nowY][nowX -1] != 0 &&
			visit[nowY][nowX - 1] == false)
		{
			q.push({ nowY,nowX - 1 });
			bUp = false;
		}

		if (nowX < lim - 1 &&
			maps[nowY][nowX + 1] != 0 &&
			visit[nowY][nowX + 1] == false)
		{
			q.push({ nowY,nowX + 1 });
			bUp = false;
		}

		if (bUp)
		{
			q.push({ nowY - 1,nowX });
		}
	}

	return -1;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		vector<vector<int>> maps(100, vector<int>(100));

		int y = 99;
		int x = 0;

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
			{
				cin >> maps[i][j];
				if (maps[i][j] == 2)
					x = j;
			}
		

		cout << '#' << n << ' ' << CheckingRoad(maps,y,x) << '\n';
	}
	return 0;
}