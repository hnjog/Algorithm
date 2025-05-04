#include<iostream>
#include<string>
#include<vector>

using namespace std;

void recur(vector<vector<int>>& map, int nowY, int nowX, vector<vector<bool>>& visited);

int count(vector<vector<int>>& map)
{
	int h = map.size();
	int w = map[0].size();
	vector<vector<bool>> visited(h, vector<bool>(w, false));

	int count = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visited[i][j] == false &&
				map[i][j] == 1)
			{
				count++;
				recur(map, i, j, visited);
			}
		}
	}

	return count;
}

void recur(vector<vector<int>>& map, int nowY, int nowX, vector<vector<bool>>& visited)
{
	int h = map.size();
	int w = map[0].size();

	if (nowY < 0 || nowX < 0 ||
		nowY >= h || nowX >= w)
		return;

	if (visited[nowY][nowX] == true ||
		map[nowY][nowX] == 0)
		return;

	visited[nowY][nowX] = true;

	recur(map, nowY + 1, nowX, visited);
	recur(map, nowY, nowX + 1, visited);
	recur(map, nowY - 1, nowX, visited);
	recur(map, nowY, nowX - 1, visited);

	recur(map, nowY - 1, nowX - 1, visited);
	recur(map, nowY + 1, nowX - 1, visited);
	recur(map, nowY - 1, nowX + 1, visited);
	recur(map, nowY + 1, nowX + 1, visited);
}

int main()
{
	while (true)
	{
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		vector<vector<int>> map(h, vector<int>(w, 0));

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int t;
				cin >> t;
				map[i][j] = t;
			}
		}

		cout << count(map) << '\n';
	}
}