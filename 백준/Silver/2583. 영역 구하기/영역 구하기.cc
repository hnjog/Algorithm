#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int m, n, k;
int areaCount = 0;

void dfs(vector<vector<int>>& map, int nowFlag, int nowY, int nowX, int& nowCount)
{
	if (nowY < 0 || nowX < 0 ||
		nowY >= m || nowX >= n)
		return;

	if (map[nowY][nowX] != 0)
		return;

	map[nowY][nowX] = nowFlag;
	nowCount++;

	dfs(map, nowFlag, nowY + 1, nowX,nowCount);
	dfs(map, nowFlag, nowY - 1, nowX,nowCount);
	dfs(map, nowFlag, nowY, nowX + 1,nowCount);
	dfs(map, nowFlag, nowY, nowX - 1,nowCount);

}

int main()
{
	cin >> m >> n >> k;
	vector<vector<int>> map(m, vector<int>(n, 0));

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x2--;
		y2--;
		for (int y = y1; y <= y2; y++)
		{
			for (int x = x1; x <= x2; x++)
			{
				map[y][x] = -1;
			}
		}
	}

	int nowFlag = 1;
	vector<int> areaVec;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 0)
			{
				int c = 0;
				dfs(map, nowFlag, i, j,c);
				nowFlag++;
				areaCount++;
				areaVec.push_back(c);
			}
		}
	}

	cout << areaCount << '\n';
	sort(areaVec.begin(), areaVec.end());
	for (int a : areaVec)
	{
		cout << a << " ";
	}
}